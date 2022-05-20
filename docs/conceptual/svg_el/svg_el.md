# SVG抽象元素

基于SVG元素的定义，实现的简单可读写的SVG对象。用于生成XML文本(outerXML)，或处理内容差异以生成DOM命令(domCMD)。

## SVGElement 基类

定义详见：「[svg_element.h](../../../core/svg_element.h)」，实现详见：「[svg_element.cpp](../../../core/svg_element.cpp)」。

### 成员

基于SVG元素中的公有特征定义的成员。包括：

#### 标签

一段字符串，描述元素的类型。默认为`<?>`。

#### 属性

在SVG抽象元素中，无视在Web上下文中属性的类型，全部认为是字符串。

#### 内容

内容是一个SVG元素列表。由此SVG元素间形成了一颗树形结构。

若被设置原生HTML，则使用原生HTML替代所有内容。

### 接口

除了提供操作成员的接口外，还提供了与DOM相关接口、运算接口。包括：

#### 标签

`get_tag()`：只读，且标签被源代码确定。

#### 属性

`get_xxx(), set_xxx()`：提供读写。参数与返回值均为字符串。写将自动更新哈希。

#### 内容

- 内容元素

    `add_inner_element(), remove_inner_element()`：提供增删。参数与返回值均为SVGElement指针。

    `get_inner_elements(), set_inner_elements()`：可读取与设置整个内部元素的列表。列表类型为存储SVGElement指针的vector。

- 原声HTML

    `set_raw_HTML(), get_raw_HTML`：设置元素的原声HTML。

#### XML文本

`outer_XML()`：由标签、属性、内容三部分生成的XML文本，可被Web渲染为SVG图像。

#### 运算符

- 比较符号

    `operator==(), operator!=()`：判断两者是否相等。基于外部哈希。（哈希算法采用的是MurmurHash，返回值类型为HASH_CODE(__int64)）

- 减号

    `operator-()`：比较差异，返回DOM命令(domCMD)。“A-B”的结果表示B如何转变为A。修改中的最小粒度为属性。

    差异算法：「[algorithm/svg_el_diff.md](../../algorithm/svg_el_diff.md)」。

## SVGElement 派生类

定义和实现详见：「[svg_el/](../../../core/svg_el/)」。

### 成员

在继承SVGElement的成员的基础上，对属性进行补充或隐藏。仍然认为类型是字符串。

其他继承内容不变。

### 接口

在继承SVGElement的接口的基础上，提供对补充属性的读写。

其他集成内容不变。

### _关于代码生成_

由于代码耦合度非常高，定义了相关代码的模板，并通过「[svg_el/.src_gen](../../../core/svg_el/.src_gen)」。

模板来自「[.svg_def](../../../core/.svg_def)」所定义的全部json文件，其中声明了一些核心中包含的SVGElement的描述信息（标签、属性与属性类型、注释）

模板中的信息来自：「[mozilla/Web/SVGElement]https://developer.mozilla.org/en-US/docs/Web/SVG/Element」