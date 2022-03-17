# 文本解析器

将输入的文本源代码转化为对应的svg

## 纯文本解析

在图形组件中插入纯文本，并对其进行样式修改

## markdown解析

处理组件中插入的markdown语法。

接收输入的markdown语法的代码；解析渲染后输出为svg的xml代码，插入到图形组件的svg中。

## katex公式解析

- 基于DVI文件格式与dvisvgm

  dvi文件是一种设备无关的可打印的文件格式。latex可以在命令行生成dvi文件，然后使用dvisgm工具将其转化为svg的xml代码。

  对环境的依赖性较大。

  - [tuxu/***latex2svg***](https://github.com/tuxu/latex2svg)

- 先转化为html（mathxl），再转化到svg对应的xml语句

  - mathjax

  - notion就是基于mathxl实现

    ```$$ \frac{a}{b+\frac{1}{2+\frac{1}{2}}} $$```

### katex解析为HTML（mathxl）

### HTML转化为svg
