# 文本矢量图

## 文本坐标系

| 坐标系         | 说明                                     |
| -------------- | ---------------------------------------- |
| 画布坐标系     | 画布的绝对坐标系                         |
| 文本组件坐标系 | 以文本外接矩形框左上角点构建的二维坐标系 |
| 文本相对坐标系 | 从文本源代码构建SVG时遵循的坐标系        |

## 文本类Text

表示文本的类，根据文本源代码解析生成基于文本矢量图

- 维护文本源代码、文本类型、样式及其解析方法

### 成员

-  文本源代码SourceText

  文本的原始字符串，需要根据文本类型以相应的规则翻译为SVG

- 文本样式TextStyle

  文本的样式

  - 纯文本：字体、颜色、大小
  - markdown：待定义
  - katex公式：待定义

- 解析器textParser

  提供解析文本源代码到SVG的规则

- SVG生成器SVGGenerator

  

### 接口

- 获取到文本源代码并修改

- 获取到SVG

  对源代码进行解析，并根据样式定义生成SVG

- 修改样式

  修改样式定义，重新解析并生成SVG

### 子类

继承自文本类的特殊文本类型



| 文本类型     | 说明                                |
| ------------ | ----------------------------------- |
| 纯文本       | 所见即所得的纯文本字符串            |
| markdown语句 | 以markdown语法定义的特殊文本字符串  |
| katex公式    | 以latex公式语法定义的特殊文本字符串 |

### 代码示例

```cpp
class TextFactory{
	textComponent createTextComponent(int type, string str);
}

class Text {
	string str;//original text or markdown/latex code
	void setStr(string str);
	virtual string getSVG();//return the xml code of svg
}

class PureText: public Text{}

class MarkdownText: public Text{}

class KatexText: public Text{}
```

- `textComponentFactory.createTextComponent(int type, string str)`

  创建文本（纯文本、markdown或latex公式）组件

  - type：文本组件类型标识符
  - str：纯文本内容或markdown/latex公式

- `textComponenet.getSVG()`

  获取到文本组件对应的SVG代码

## 文本矢量图类TextSVG

使用组件坐标系的矢量图，是文本的装饰器

- 将文本映射到组件坐标系

### 成员

- 文本

- 坐标映射

  标记文本在组件坐标系中的位置。通过记录文本坐标系原点在组件坐标系中的位置，将基于文本坐标系的SVG映射到组件坐标系中。

  考虑到一个组件中可以插入多个文本，同一个组件每个文本矢量图的坐标原点应当彼此不同。

- SVG生成器SVGGenerator

### 接口

- 更新

  对文本源代码进行更新，并重新解析获取到文本SVG

## 组件文本矢量图类ComponentTextSVG

使用画布坐标系的文本矢量图。以组件坐标系的原点及两条坐标轴构建文本的外接矩形框。

- 将一个或多个文本矢量图封装进外接矩形框中，并构成组件
- 将组件根据布局映射到画布坐标系中

### 成员

- 文本矢量图

- 布局

  描述文本组件如何呈现在画布上。

  - 基于文本的外接矩形描述文本矢量图

  - 组件坐标系到画布坐标系的映射
  - 文本组件的位置修改、旋转

### 接口

- 更新

  每次更新（文本源代码）时，从内到外重新逐层解析及映射。

  其中在从组件坐标系到画布坐标系映射（即组件层的映射）时，需要根据布局实现。

- 绘制

  文本矢量图完成绘制后，将文本矢量图按照布局进行变换，映射到画布坐标系。
