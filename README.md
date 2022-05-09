# Lewzen-core - SVG Component Core of Lewzen

## Usage

### SVG Element Interface

- Creating SVG Element Interface

    ```cpp
    // Object
    //auto obj = SVGIRect(); // not recommended with bad weak ptr

    // Pointer
    #include <memory>
    auto ptr = std::make_shared<Lewzen::SVGICircle>();
    ```

    Creating SVG Element Interface via object is not recommended because it is inherited from std::enable_shared_from_this which is used to maintain parent relationship. The safe way of initialization is std::make_shared.

- Setting Attributes

    ```cpp
    auto el = std::make_shared<Lewzen::SVGIMask>();
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

        All attributes support legal strings, which matches their regular expressions. Legal strings can be pointers 'char *' when assigning.

    - Binding attribute with arbitary function

        By 'operator[]' or 'bind', you can bind attribute with a function. This function could be normal function (function pointer), std::function, member function or even lambda function.

        - Normal function and std::function

            Can be used directly. Note that the return value **must** be 'const'.

            ```cpp
            const double return_pi() { return 3.14; }
            ```

        - member function

            You should std::bind the member function to an object firstly. Note that the return value **must** be 'const'.

            ```cpp
            std::bind(&Obj::_from_con_val_integer, *obj);
            ```

        - lambda function

            There's return value constraint. Lambda function won't cast type to legal ctype statically. For example, you **should not** return 'char *' as a string.

            ```cpp
            //auto lambda = [](){ return "123"; } // illegal with std::bad_function_call
            auto lambda = [](){ return std::string("123"); }
            ```

        - Solution to static cast problem

            In case there might be some function cannot be cast where compiler cannot deduce type automatically, we introduced a method to deal with any cast problem you could meet with function binding:

            ```cpp
            std::function<const Type()> func = func_with_problem;
            ```

            Now you can use `func` normally just as std::function.

    - Binding attribute with weak pointer

        By 'operator[]' or 'bind', you can bind attribute with a weak pointer. We only support weak pointer to prevent memory leaks, which means you should maintain these smart pointers manually. Note that weak pointers to be bound do not need 'const'. For string, we **do not** support 'char *' pointers.

- Managing inner content

    SVG Element Interface owns a a list of children elements.

    - Inner elements

        Theres a shared pointer list of SVG Element Intefaces. You can add a new pointer to its tail or remove all same pointers from it:-

        ```cpp
        auto p = std::make_shared<Lewzen::SVGICircle>();
        el->add(p); // add
        el->add(p, i); // add at index i
        el->remove(p); // remove by content
        el->remove(p, true); // remove all by content
        el->remove(i); // remove at index i
        ```

        An element can be child of only one parent. If an child element is added to another parent element, it will be first removed from original parent. Removing an element is based on content rather than pointer.

        If a complicated list operation is needed, you can get and set the whole list:

        ```cpp
        auto list = el->children(); // get children
        el->children(list); // set children
        ```

- Raw HTML

    You can set raw HTML to replace all content, where outer XML will be equal to the HTML string.

    ```cpp
    el->RawHTML = "this is a text string";
    el->RawHTML = "<div>this is an HTML string</div>";
    ```

    This adds support for inner texts, inner comments and custom elements.

    `RawHTML` is an attribute, which means binding is also available.

- Assigning and Cloning

    You can assign another element to an element:

    ```cpp
    *el1 = *el2;
    ```

    This will run a deep copy including all descendants.

    You can also get a copy from itself:

    ```cpp
    auto el = std::make_shared<Lewzen::SVGICircle>();
    auto copy1 = el->clone(); // std::shared_ptr<SVGElement>
    auto copy2 = el->clone(true); // std::shared_ptr<SVGICircle>
    ```

    The default returning value will be cast to SVG Element because it is an overridden function. Adding an boolean parameter, it will return the original type. Note that clone **won't** copy bindings of attributes, which means you should maintain those bindings manually.

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

        For string parameter without white-spaces, it will enclosed by '`\"`'；Otherwise, a length parameter is needed.

        <table stye="table-layout:fixed;">
        <tr><th><div style="width:220px;text-align:center">Command</div></th> <th style="text-align:center">Equivalent Javascript Code</th></tr>
        <tr>
        <td style="text-align:center">
        
        `child <index:int>`
        
        </td>
        <td>

        ```javascript
        current = current.childNodes[index];
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
        current.removeChild(current.childNodes[index]);
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `append <len:int> <xml:str>`
        
        </td>
        <td>

        ```javascript
        current.insertAdjacentHTML('beforeend', xml);
        ```

        </td>
        </tr>
        <tr>
        <td style="text-align:center">
        
        `sort "<indices:list>"`
        
        </td>
        <td>

        ```javascript
        [...current.childNodes]
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
        </table>

### Geometry

- Point2D

    A point class with coordinate system declared.

    - Initialization

        ```cpp
        auto p_null = Point2D(0.5, -0.2); // null coordinate system
        auto p_coord = Point2D(1, 0, Lewzen::CanvasCoordinateSystem()); // with specific coordinate system
        auto p_canvas = Lewzen::canvas_point(100, 200); // with canvas coordinate system
        auto p_compo = comp->create_point(200, -100); // with certain component coordinate system
        ```

    - Getters & Setters

        ```cpp
        p.get_x(), p.get_y(); // getters
        p.set_x(x), p.set_y(y); // setters
        ```

        Change it's coordinate system is not allowed.

    - Operations

        1. Comparation

            ```cpp
            p1 == p2;
            p1 != p2;
            ```
        2. Translation

            ```cpp
            p1 = p2;
            p1 += p2;
            p1 -= p2;
            p1.move(x, y);
            ```

        3. Plus & Minus

            ```cpp
            p3 = p1 + p2;
            p4 = p1 - p2;
            ```
            
        4. Coordinate System Conversion

            ```cpp
            Lewzen::CanvasCoordinateSystem coord;
            p2 = p1(coord);
            ```

    - Events

        1. On Update

            ```cpp
            p.on_update([](const double &lx, const double &ly,
                                             const double &x, const double &y) {
                std::cout << "last position: " << lx << " " << ly << std::endl;
                std::cout << "new position: " << x << " " << y << std::endl;
                // do something
            });
            ```

            On update event  won't emit unless x or y position is changed numerically.

- Component Rotatable

    ComponentRotatable is an abstract class used to describe rotation and parent relation. ComponentCoordinateSystem uses it to handle rotation.

    - Abstract part

        ```cpp
        virtual std::weak_ptr<ComponentRotatable> get_parent() const = 0;
        ```
        
        `get_parent` is abstract, you should maintain parent node manually in a derived class:

        ```cpp
        class MyComponent: public Lewzen::ComponentRotatable {
        private:
            std::vector<std::shared_ptr<MyComponent>> children;
            std::weak_ptr<MyComponent> parent;
        protected:
            // Realization of get_parent
            virtual std::weak_ptr<ComponentRotatable> get_parent() const {
                return parent;
            }
        public:
            // Empty Constructor
            MyComponent(): ComponentRotatable() {}
            // Construct with SVGI
            MyComponent(const std::weak_ptr<Lewzen::SVGIElement> &svg_element_interface): ComponentRotatable(svg_element_interface) {}
            // Add a new child
            void add_child(const std::shared_ptr<MyComponent> &component) {
                if (auto sp = component->parent.lock()) {
                    sp->children.erase(std::remove(sp->children.begin(), sp->children.end(), component), sp->children.end());
                }
                component->parent = shared_from_base<MyComponent>();
                children.push_back(component);
            }
        };
        ```

    - Rotation

        1. Rotation Center

            Rotation center is point in this component's coordinate system.

            ```c++
            component.get_rotate_center();
            component.set_rotate_center(x, y); // by position
            component.set_rotate_center(p); // by another point
            ```

        2. Theta

            Theta is the radian of rotation (clockwise).

            ```c++
            component.get_theta();
            component.set_theta(theta);
            ```

    - ComponentCoordinateSystem

        Component uses itself to describte its ComponentCoordinateSystem, which contains rotation.

        You can get this ComponentCoordinateSystem by `get_coordinate_system()`. To easily create points in this coordinate system, you can use `create_point(x, y)`. If coordiante conversion is need, `to_canvas()` and `from_canvas()` is also provided.

- Coordinate Systems

    - 
- Built-in Point Functions

## Include & Build

### Include

```cpp
#include <lewzen-core/core.h>
```

### Build

```shell
g++ -o <your out> <your works> lewzen.lib 
```