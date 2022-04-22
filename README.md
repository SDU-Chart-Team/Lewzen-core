# Lewzen-core - SVG Component Core of Lewzen

## Usage

### SVG Element Interface

- Creating SVG Element Interface

    ```cpp
    // Object
    //auto obj = SVGIRect(); // not recommended with bad weak ptr

    // Pointer
    #include <memory>
    auto ptr = std::make_shared<SVGICircle>();
    ```

    Creating SVG Element Interface via object is not recommended because it is inherited from std::enable_shared_from_this which is used to maintain parent relationship. The safe way of initialization is std::make_shared.

- Setting Attributes

    ```cpp
    auto el = std::make_shared<SVGIMask>();
    auto &height = el->height;

    // Assignment
    height.set("1.5px"); // by member function
    height = 12; // by operator

    // Binding with function
    long return_width() { return std::string("100"); }
    height.bind(return_width); // by member function
    auto lambda = [&]() { return 2.0f; }
    height[lambda]; // by operator

    // Binding with weak pointer
    std::weak_ptr<std::string> p = std::make_shared<std::string>("3.0e-3em");
    height.bind(p); // by member function
    height[p]; // by operator
    ```

    - Assigning value directly

        By 'operator=' or 'set', you can assigning cvalue of ctype to an attribute directly. Note there are constraints on ctype for every attribute. If ctype not matches, there will be warnings when you are in debug mode.

        All attributes support legal strings, which matches their regular expressions. Legal string can be 'char *' in assignment.

    - Binding attribute with arbitary function

        By 'operator[]' or 'bind', you can bind attribute with a function. This function could be normal function (function pointer), std::function, member function or even lambda function.

        - Normal function and std::function

            Can be used directly. Note that the return value must be 'const'.

        - member function

            You should std::bind the member function to an object firstly. And note that the return value must be 'const'.

            ```cpp
            std::bind(&Obj::_from_con_val_integer, *obj);
            ```

        - lambda function

            There's return value constraint. Lambda function won't cast type to legal ctype statically. For example, you should not return 'char *' as a string.

            ```cpp
            //auto lambda = [](){ return "123"; } // illegal
            auto lambda = [](){ return std::string("123"); }
            ```

        - Solution to static cast problem

            In case there might be some function cannot be cast where compiler cannot deduce type automatically, we introduced a method to deal with any cast problem you could meet with function binding:

            ```cpp
            std::function<const Type()> func = func_with_problem;
            ```

            Now you can use `func` normally just as std::function.

    - Binding attribute with weak pointer

        By 'operator[]' or 'bind', you can bind attribute with a weak pointer. We only support weak pointer to prevent memory leaks, which means you should maintain these smart pointers manually. Note that weak pointers to be bound do not need 'const'. For string, we do not support 'char *' pointers.

- Managing inner content

    SVG Element Interface owns a content string and a list of children elements.

    - Inner content rendering order

        ```html
        <el>
            content-string
            <content-el.0/>
            <content-el.1/>
            ...
        </el>
        ```

    - Inner content string

        Content string can be arbitary string, including HTML.

    - Inner elements

        A shared pointer list of SVG Element. (SVG Element Interfaces are derived from SVG Element)

        You can add a new pointer to its tail or remove all same pointers from it:

        ```cpp
        auto p1 = std::make_shared<SVGCircle>();
        auto p2 = std::make_shared<SVGICircle>();
        el->add_inner_element(p1); // add
        el->remove_inner_element(p2); // remove
        el->remove_inner_element(p2, true); // remove all
        ```

        An element can be child of only one parent. If an child element is added to another parent element, it will be first removed from original parent. Removing an element is based on content rather than pointer.

        If a complicated list operation is needed, you can get and set the whole list:

        ```cpp
        auto list = el->get_inner_elements();
        el->set_inner_elements(list);
        ```

- Assigning and Cloning

    You can assign another element to an element:

    ```cpp
    *el1 = *el2;
    ```

    This will run a deep copy including all descendants.

    You can also get a copy from itself:

    ```cpp
    auto el = std::make_shared<SVGICircle>();
    auto copy1 = el->clone(); // std::shared_ptr<SVGElement>
    auto copy2 = el->clone(true); // std::shared_ptr<SVGICircle>
    ```

    The default returning value will be cast to SVG Element because it is an overridden function. Adding an boolean parameter, it will return the original type.

- Rendering

    Commit all modifications and rendering. There's two ways of rendering:

    - Outer XML

        ```cpp
        el->outer_SVG();
        ```

        This returns SVG content including all attributes and all its children.

    - Differences between 2 SVGs expressed by DOM commands

        ```cpp
        *el1 - *el2;
        ```

        This returns SVG differences by a series of DOM commands. These commands will explain how to change `el2` to `el1`.
    
    - Update commitment described by DOM commands

        For SVG Element Interfaces, you can commit update and get DOM commands to describe those changes.

        ```cpp
        el->commit();
        ```

    - **DOM commands**:

        Any white-spaces including '` `', '`\t`', '`\n`' are considered to be delimiters.

        For string parameter without white-spaces, it will enclosed by '`\"`'；Otherwise, a length parameter is need.

        <table stye="table-layout:fixed;">
        <tr><th><div style="width:220px;text-align:center">Command</div></th> <th style="text-align:center">Equivalent Javascript Code</th></tr>
        <tr>
        <td style="text-align:center">
        
        `child <index:int>`
        
        </td>
        <td>

        ```javascript
        current = current.children[index];
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `parent`
        
        </td>
        <td>

        ```javascript
        current = current.parentNode;
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `remove <index:int>`
        
        </td>
        <td>

        ```javascript
        current.children[index].remove();
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `append <len:int> <xml:str>`
        
        </td>
        <td>

        ```javascript
        let append = new DOMParser().parseFromString(xml, "text/xml");
        current.appendChild(append.documentElement);
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `replace <len:int> <xml:str>`
        
        </td>
        <td>

        ```javascript
        let replace = new DOMParser().parseFromString(xml, "text/xml");
        current.parentNode.replaceChild(current, replace.documentElement);
        current = replace;
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `sort "<indices:list>"`
        
        </td>
        <td>

        ```javascript
        [...current.children]
        .map((node,i)=>{node._index=indices[i];return node;})
        .sort((a,b)=>a._index>b._index?1:-1)
        .forEach(node=>current.appendChild(node));
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `modify <attr:str> "<val:str>"`
        
        </td>
        <td>

        ```javascript
        current.setAttribute("attr", "val");
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `reset <attr:str>`
        
        </td>
        <td>

        ```javascript
        current.removeAttribute("attr");
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `content <len:int> <content:str>`
        
        </td>
        <td>

        ```javascript
        current.childNodes[0].nodeValue = content;
        ```

        </td>
        </tr>
        </table>

### Component

...

## Compile

- g++

    ```shell
    g++ <your works> lewzen-core.lib -o <your app>
    ```