# 组件布局

含有与一个组件布局相关的属性。

## 组件布局类 LZArrange

### 属性

- 组成

    - o_pos: Point2D

        组件的图形中心在画布上的位置。友元。（当ComponentGraph更新时，自动调整）

    - r_pos: Point2D

        组件的旋转中心在图形坐标系的位置。友元。

    - radian: double

        组建的旋转弧度。友元。

- 描述

    - _type: enum

        布局类型。保护，只读。

### 函数

- 构造

    - LZArrange(o_pos: Point2D, r_pos: Point2D, radian: double = 0)

        设置属性。

- 坐标系变换

    - layout_transform() -> PointTransform

        图形坐标系到画布坐标系的映射。

## 线形布局 LZArrangeLine

继承布局，用于线形组件。

### 属性

- 组成

    - start_point: Point2D *

        线的起点。私有。

    - end_point: Point2D *

        线的终点。私有。

### 函数

- 构造

    - LZArrangeLine(start_point: Point2D *, end_point: Point2D *, radian: double = 0, type: enum = -1)

        定义图形起止点。

## 矩形布局 LZArrangeRect

继承布局，用于矩形组件。

### 属性

- 组成

    - TL_point, BR_point: Point2D *

        矩形的两顶点。私有。

    - width: double

        宽度，由两顶点导出。更改时将改变BR_point位置。

    - height: double

        高度，由两顶点导出。更改时将改变BR_point位置。

### 函数

- 构造

    - LZArrangeLine(TL_point: Point2D *, ...., radian: double = 0)

        定义矩形两顶点。