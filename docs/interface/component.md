# 组件

表示Lewzen中包含的一个组件，包含了一切行为、规则、上下文。一个组件由三个部分组成：[矢量图](vg/vg.md)、[文字](txt/txt.md)、[布局](arg.md)。其中布局为组件整体在画布中的表现、矢量图描述了图形的样式与变化规则、文字描述了文字样式与内容。

矢量图、文字中使用都是相对自己的图形坐标系。组件对其中的一些方法进一步封装，转化为画布坐标系。

## 组件类 LZComponent

### 属性

- 组成

    - arrange: LZArrange *

        组件布局对象的指针。只读。

    - vector_graph: LZVectorGraph *

        组件矢量图对象的指针。只读。

    - text: LZText *

        组件文字对象的指针。只读。

    - G: ComponentGraph *

        组件矢量图和文字变换到画布坐标系得到的图。只读。

- 描述

    - author: string

        作者。

    - comment: string

        注释。

    - thumbnail: string

        缩略图路径。

### 函数

- 构造函数

    - LZComponent()

        空组件。

    - LZComponent(desc: string)

        通过描述性指令创建组件。

    - LZComponent(json: string)

        通过json描述创建组件。

    - LZComponent(xml: string)

        通过XML描述创建组件。

- 析构函数

    - ~LZComponent()

        释放所有组件拥有的资源。

- 功能函数

    - redraw()

        重新计算G。流程包括矢量图、文字图生成、更新图形坐标系、坐标系变换。

    - to_SVG() -> string

        返回当前状态的组件在画布上的svg文本。

    - to_SVG(x: double, y: double, w: double, h: double) -> string

        返回当前状态的组件被映射到画布上的(x, y, w, h)视角中的的svg文本。

    - move_to(p: Point2D)

        将组件的图形中心移动到指定位置。重绘。（画布坐标系）

    - move_rotate_center_to(p: Point2D)

        将组件的旋转中心移动到指定位置。重绘。（图形坐标系）

    - rotate_to(rd: double)

        将组件相对旋转中心旋转为rd弧度。重绘。

- 矢量图相关函数

    - move_critical_to(cp_id: string, p: Point2D)

        将关键点移动至指定位置。重绘。（画布坐标系）

- 文字相关函数

    - change_text_area(w: double, h: double)

        变更文字绘制区域。重绘。