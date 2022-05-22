set platform=%1
set ver=%date:~0,4%-%date:~5,2%-%date:~8,2%
cd core
if [%platform%]==[wasm] (
    make cc=em++ ar=emar
    cd ..
    if not exist ".\release" mkdir .\release
    xcopy .\core\ .\release\lewzen-core\ /s /e
    del .\core\lewzen-core.lib
    cd .\release\lewzen-core
    del .\.attr_def /s /q
    rmdir .\.attr_def /s /q
    del .\.attr_def /s /q
    rmdir .\.attr_def /s /q
    del .\.svg_def /s /q
    rmdir .\.svg_def /s /q
    del .\svg_el/.src_gen /s /q
    rmdir .\svg_el/.src_gen /s /q
    del .\svgi_el/.src_gen /s /q
    rmdir .\svgi_el/.src_gen /s /q
    del .\svgi_el/attr/.src_gen /s /q
    rmdir .\svgi_el/attr/.src_gen /s /q
    del .\json.hpp
    move .\lewzen-core.lib ..\lewzen-core.lib
    del .\Makefile
    del .\geometry\Makefile
    del .\geometry\coordinate_system\Makefile
    del .\svg_el\Makefile
    del .\svgi_el\Makefile
    del .\svgi_el\attr\Makefile

    cd ..\..
    del /s /q /f *.o
    7z a -t7z -r ..\lewzen-core-win-em++-%ver%.7z release\*

    del .\release\ /s /q
    rmdir .\release\ /s /q
) else (
    emmake make cc=clang++ ar=llvm-ar
    cd ..
    if not exist ".\release" mkdir .\release
    xcopy .\core\ .\release\lewzen-core\ /s /e
    del .\core\lewzen-core.lib
    cd .\release\lewzen-core
    del .\.attr_def /s /q
    rmdir .\.attr_def /s /q
    del .\.attr_def /s /q
    rmdir .\.attr_def /s /q
    del .\.svg_def /s /q
    rmdir .\.svg_def /s /q
    del .\svg_el/.src_gen /s /q
    rmdir .\svg_el/.src_gen /s /q
    del .\svgi_el/.src_gen /s /q
    rmdir .\svgi_el/.src_gen /s /q
    del .\svgi_el/attr/.src_gen /s /q
    rmdir .\svgi_el/attr/.src_gen /s /q
    del .\json.hpp
    move .\lewzen-core.lib ..\lewzen-core.lib
    del .\Makefile
    del .\geometry\Makefile
    del .\geometry\coordinate_system\Makefile
    del .\svg_el\Makefile
    del .\svgi_el\Makefile
    del .\svgi_el\attr\Makefile

    cd ..\..
    del /s /q /f *.o
    7z a -t7z -r ..\lewzen-core-win-clang++-%ver%.7z release\*

    del .\release\ /s /q
    rmdir .\release\ /s /q
)