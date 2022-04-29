# SVG元素接口

对[SVG抽象元素](../svg_el/svg_el.md)进行扩展。每个SVGElement都有一个对应的SVGElementInterface。SVG元素接口的作用是提供对属性的适配，将C++中的类型通过[SVG属性](attr.md)映射为对应的合法属性字符串，以此提供标准并简化操作。

非基类SVGElementInterface将同时继承基类SVGElementInterface和对应的SVGElement，这将出现菱形继承，因此统一通过基类SVGElementInterface访问基类SVGElement

## 成员

所有继承自SVGElement的成员都被隐藏。额外提供对应SVG属性对象。

## 接口

所有对SVG抽象元素中属性字符串的读写均被隐藏，取而代之的是SVG属性对象，并且以属性的方式(结构体风格)被访问。

其他来自SVG抽象元素的接口仍被保留，包括：标签、内容、XML文本、运算符。

### 提交

SVG元素接口引入了提交区。所有写操作被暂存至提交区，提交时统一写入。 提交将返回DOM命令(domCMD)。

提交算法：「[algorithm/svgi_el_commit.md](../../algorithm/svgi_el_commit.md)」。