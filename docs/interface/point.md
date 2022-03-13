# 二维点

一个二维点的概念。除了坐标外，还包含描述信息例如类型、所在坐标系。

## 二维点类 Point2D

### 属性

- 坐标

    - x, y: double

        点的坐标。

- 描述

    - coordinate: Coordinate

        点所在的坐标系。只读。

    - type: string

        点的类型。只读。

    - comment: string

        点的注释。只读。

### 函数

- 构造

    - Point2D(x, y)

        一个新的二维点。

- 析构函数

    - ~Point2D()

        释放资源。

- 变换

    - transform(trans: Transform) -> Point2D

        进行点的变换。