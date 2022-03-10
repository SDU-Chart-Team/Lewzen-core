# 性能

原始svg在浏览器引擎中的呈现可以有如下三种方式：

1. Decode为DOM对象'\<svg\>'
2. 通过base64编码为图像，然后在canvas上绘制
3. 转化为blob对象，生成url，然后在canvas上绘制

关于选择这三种方式的理论基础：

- DOM对象

    一种最直观最先能想到的方式。由于原始svg就是基于XML，并且能直接由Html使用，因此前端能够直接将原始svg的代码嵌入网页中。

    这种方法的瓶颈之一是解码，即原始svg转换为DOM对象的过程。使用DOMParser的parseFromString方法可以将一段XML转化为DOM对象，而这个过程就是一个计算热点。

    其二在于DOM的管理。一种我们最希望的方式是直接渲染图像本身，而不进行额外的操作，因为后端及核心已经完成了计算。换句话说，由于我们主要使用本核心来完成对svg的生成及改动，所以我们传入的svg对前端来说是静态的。但是使用DOM对象，就不得不需要对DOM进行维护，因为DOM对象默认是动态的。这既会带来维护的额外开销，也会带来渲染及绘图的额外成本。

- Canvas + base64

    Canvas是一种目前逐渐流行的渲染方案，避免了DOM的额外开销而直接进行渲染。

    canvas+base64是一种流行的在canvas上渲染svg的方法，它利用的是浏览器支持渲染base64编码的机制。canvas虽然不支持绘制svg，但支持绘制图像。
    
    base64是一种常见的二进制编码方式，它可以被直接嵌入至Html文档中，便于在网页中表示小附件。浏览器支持将接收到的base64编码渲染为指定形式，例如图像。

    这个方法的思路就是首先将原始svg编码为base64图像，然后再将其嵌入到一个临时图片对象中，最后以canvas渲染。此过程经历了一次编码和解码，即先将svg编码为base64，再由canvas解码为图像。

    整个过程几乎只有计算，存储图像的开销是编码本身，因此十分节省内存。但是编码和解码过程是计算热点，十分耗时。

- Canvas + blob

    这是另一种流行的在canvas上渲染svg的方法，它利用的是表示二进制图像字节流的Blob对象。

    Blob对象常用于视频播放、图像下载，和base64类似但不是嵌入文档中。Blob优势在于其体量比base64小的多，这也就意味着渲染和绘制的时间很短。使用blob，由于它直接支持svg，我们就不需要显式的对base64进行编码了。Blob对象可以直接生成一个url，所以我们可以直接将临时图像变量的src指向该url。

    但是Blob的问题在于当创建对象后，原始的二进制字节流即使被渲染，仍然会在内存中留下拷贝，这会导致内存开销相当大。随着网页中渲染对象的增多，拷贝也随之增多，一旦浏览器内存达到阈值，随之而来的是频繁的垃圾回收。这带来了额外的成本。

## 性能测试

使用相同的svg模板进行测试。该svg中除了包含路径、透明填充外，还包含图片。

- DOM对象

    ```html
    <input id='bt' type="button" onclick="add_img()" value="Add1"/>
    <div style="height: 800px; width: 1500px;"></div>

    <script>
    const new_img = (x, y) => {
        var div = document.querySelector('div');
        var html = '<svg xmlns="http://www.w3.org/2000/svg" width="467" height="462" id="source">'
        +  '<rect x="80" y="60" width="250" height="250" rx="20" style="fill:#ff0000; stroke:#000000;stroke-width:2px;"/>'
        +  '<rect x="140" y="120" width="250" height="250" rx="40" style="fill:#0000ff; stroke:#000000; stroke-width:2px; fill-opacity:0.7;"/>'
        +  '<image xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="data:image/png;base64,<某个图片的base64>" width="230px" x="80" y="180"/>'
        +'</svg>';
        let svg = new DOMParser().parseFromString(html, 'text/html').querySelector('#source');
        svg.style.position = 'absolute';
        svg.style.left = x + 'px';
        svg.style.top = y + 'px';
        svg.style.pointerEvents = 'none';
        div.appendChild(svg);
    }

    new_img(0, 0);
    window.cnt = 0;

    const add_img = () => {
        x = Math.random() * 1420;
        y = Math.random() * 720;

        new_img(x, y);
        var btn = document.querySelector('#bt');
        window.cnt++;
        btn.value = 'Add' + window.cnt;
        console.log(btn);
    }
    </script>
    ```

- Canvas + base64

    ```html
    <input id='bt' type="button" onclick="add_img()" value="Add1"/>
    <canvas height="800px" width="1500px"></canvas>

    <script>
    const new_img = (x, y) => {
        var img = document.createElement('img');
        var canvas = document.querySelector('canvas');
        img.style.width  = '462px';
        img.style.height = '467px';
        var html = '<svg xmlns="http://www.w3.org/2000/svg" width="467" height="462" id="source">'
        +  '<rect x="80" y="60" width="250" height="250" rx="20" style="fill:#ff0000; stroke:#000000;stroke-width:2px;"/>'
        +  '<rect x="140" y="120" width="250" height="250" rx="40" style="fill:#0000ff; stroke:#000000; stroke-width:2px; fill-opacity:0.7;"/>'
        +  '<image xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="data:image/png;base64,<某个图片的base64>" width="230px" x="80" y="180"/>'
        +'</svg>';
        img.src = 'data:image/svg+xml;base64,' + window.btoa(html);
        img.onload = function() {
            canvas.getContext('2d').drawImage(img, x, y);
        }
    }

    new_img(0, 0);

    window.cnt = 1;
    const add_img = () => {
        x = Math.random() * (1500-467);
        y = Math.random() * (800-462);

        new_img(x, y);
        var btn = document.querySelector('#bt');
        window.cnt++;
        btn.value = 'Add' + window.cnt;
    }
    </script>
    ```

- Canvas + blob

    ```html
    <input id='bt' type="button" onclick="add_img()" value="Add1"/>
    <canvas height="800px" width="1500px"></canvas>

    <script>
    const new_img = (x, y) => {
        var img = document.createElement('img');
        var canvas = document.querySelector('canvas');
        img.style.width  = '462px';
        img.style.height = '467px';
        
        var html = '<svg xmlns="http://www.w3.org/2000/svg" width="467" height="462" id="source">'
        +  '<rect x="80" y="60" width="250" height="250" rx="20" style="fill:#ff0000; stroke:#000000;stroke-width:2px;"/>'
        +  '<rect x="140" y="120" width="250" height="250" rx="40" style="fill:#0000ff; stroke:#000000; stroke-width:2px; fill-opacity:0.7;"/>'
        +  '<image xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="data:image/png;base64,<某个图片的base64>" width="230px" x="80" y="180"/>'
        +'</svg>';
        
        var svg = new Blob([html], {type:"image/svg+xml;charset=utf-8"}),
            domURL = self.URL || self.webkitURL || self,
            url = domURL.createObjectURL(svg),
            img = new Image;

        img.onload = function () {
            canvas.getContext('2d').drawImage(this, x, y);
            domURL.revokeObjectURL(url);
        };
        img.src = url;
    }

    new_img(0, 0);

    window.cnt = 1;
    const add_img = () => {
        x = Math.random() * (1500-467);
        y = Math.random() * (800-462);

        new_img(x, y);
        var btn = document.querySelector('#bt');
        window.cnt++;
        btn.value = 'Add' + window.cnt;
    }
    </script>
    ```

模拟点击事件绘制svg图像，重复500次，得到在压力环境下的性能测试结果：

- 耗时

    忽略Idle时间，以下是总运算耗时：

    ![](https://s2.loli.net/2022/03/10/KwsZnaIliUScA62.png)

    离中心越远则耗时越短。

- 总耗时、绘图方法耗时

    ![](https://s2.loli.net/2022/03/10/s6afY9uqE1kcZjg.png)

- 计算热点

    |DOM|Canvas+base64|Canvas+blob|
    |:-|:-|:-|
    |append: 6972.2ms|drawImage: 3005.9ms|blob: 874.1ms|
    |parse: 4373.8ms|btoa: 2458.8ms|gc: 579.7ms|


## 结论

|方案|优点|缺点|瓶颈|
|:-:|:-|:-|:-|
|DOM对象|<ul><li>前端代码简单</li><li>自动加载</li><li>自动渲染</li></ul>|<ul><li>较长的加载时间</li><li>DOM的维护较为缓慢</li><li>渲染缓慢</li><li>绘制时间相对较长</li></ul>|DOM维护、decode|
|Canvas+base64|<ul><li>加载的工作交给btoa</li><li>内存消耗小</li><li>渲染、绘制时间较短</li></ul>|<ul><li>脚本时间过长</li><li>一次encode和一次decode过程</li></ul>|一次encode(btoa)一次encode(drawImage)|
|Canvas+blob|<ul><li>加载的工作交给blob</li><li>渲染、绘制时间最短</li><li>脚本时间较短</li></ul>|<ul><li>内存消耗十分大</li><li>大量时间用于GC</li></ul>|GC|

## 选择

1. 渲染规模较小时，使用DOM对象
2. 渲染规模大，但内存足够时，使用Canvas+blob
3. 渲染规模打，但内存不足时，使用Canvas+base64