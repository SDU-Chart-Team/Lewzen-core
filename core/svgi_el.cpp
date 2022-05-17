#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "svgi_el.h"

namespace Lewzen {
    SVGIElement::SVGIElement(): SVGElement() {
        _bind_getter_setter();
    }
    void SVGIElement::_bind_getter_setter() {
        std::function<const std::string()> _getter_id = std::bind(&SVGElement::get_id, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_id = std::bind(&SVGElement::set_id, (SVGElement *)this, std::placeholders::_1);
        Id.set_getter(_getter_id), Id.set_setter(_setter_id);
        Id.callback_assign(_attr_on_assign[0]), Id.callback_bind_func(_attr_on_bind[0]), Id.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_lang = std::bind(&SVGElement::get_lang, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_lang = std::bind(&SVGElement::set_lang, (SVGElement *)this, std::placeholders::_1);
        Lang.set_getter(_getter_lang), Lang.set_setter(_setter_lang);
        Lang.callback_assign(_attr_on_assign[1]), Lang.callback_bind_func(_attr_on_bind[1]), Lang.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_tabindex = std::bind(&SVGElement::get_tabindex, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_tabindex = std::bind(&SVGElement::set_tabindex, (SVGElement *)this, std::placeholders::_1);
        Tabindex.set_getter(_getter_tabindex), Tabindex.set_setter(_setter_tabindex);
        Tabindex.callback_assign(_attr_on_assign[2]), Tabindex.callback_bind_func(_attr_on_bind[2]), Tabindex.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_xmlZbase = std::bind(&SVGElement::get_xmlZbase, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_xmlZbase = std::bind(&SVGElement::set_xmlZbase, (SVGElement *)this, std::placeholders::_1);
        XmlBase.set_getter(_getter_xmlZbase), XmlBase.set_setter(_setter_xmlZbase);
        XmlBase.callback_assign(_attr_on_assign[3]), XmlBase.callback_bind_func(_attr_on_bind[3]), XmlBase.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_xmlZlang = std::bind(&SVGElement::get_xmlZlang, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_xmlZlang = std::bind(&SVGElement::set_xmlZlang, (SVGElement *)this, std::placeholders::_1);
        XmlLang.set_getter(_getter_xmlZlang), XmlLang.set_setter(_setter_xmlZlang);
        XmlLang.callback_assign(_attr_on_assign[4]), XmlLang.callback_bind_func(_attr_on_bind[4]), XmlLang.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_xmlZspace = std::bind(&SVGElement::get_xmlZspace, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_xmlZspace = std::bind(&SVGElement::set_xmlZspace, (SVGElement *)this, std::placeholders::_1);
        XmlSpace.set_getter(_getter_xmlZspace), XmlSpace.set_setter(_setter_xmlZspace);
        XmlSpace.callback_assign(_attr_on_assign[5]), XmlSpace.callback_bind_func(_attr_on_bind[5]), XmlSpace.callback_bind_ptr(_attr_on_bind[5]);
        std::function<const std::string()> _getter_class = std::bind(&SVGElement::get_class, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_class = std::bind(&SVGElement::set_class, (SVGElement *)this, std::placeholders::_1);
        Class.set_getter(_getter_class), Class.set_setter(_setter_class);
        Class.callback_assign(_attr_on_assign[6]), Class.callback_bind_func(_attr_on_bind[6]), Class.callback_bind_ptr(_attr_on_bind[6]);
        std::function<const std::string()> _getter_style = std::bind(&SVGElement::get_style, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_style = std::bind(&SVGElement::set_style, (SVGElement *)this, std::placeholders::_1);
        Style.set_getter(_getter_style), Style.set_setter(_setter_style);
        Style.callback_assign(_attr_on_assign[7]), Style.callback_bind_func(_attr_on_bind[7]), Style.callback_bind_ptr(_attr_on_bind[7]);
        std::function<const std::string()> _getter_onbegin = std::bind(&SVGElement::get_onbegin, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onbegin = std::bind(&SVGElement::set_onbegin, (SVGElement *)this, std::placeholders::_1);
        Onbegin.set_getter(_getter_onbegin), Onbegin.set_setter(_setter_onbegin);
        Onbegin.callback_assign(_attr_on_assign[8]), Onbegin.callback_bind_func(_attr_on_bind[8]), Onbegin.callback_bind_ptr(_attr_on_bind[8]);
        std::function<const std::string()> _getter_onend = std::bind(&SVGElement::get_onend, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onend = std::bind(&SVGElement::set_onend, (SVGElement *)this, std::placeholders::_1);
        Onend.set_getter(_getter_onend), Onend.set_setter(_setter_onend);
        Onend.callback_assign(_attr_on_assign[9]), Onend.callback_bind_func(_attr_on_bind[9]), Onend.callback_bind_ptr(_attr_on_bind[9]);
        std::function<const std::string()> _getter_onrepeat = std::bind(&SVGElement::get_onrepeat, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onrepeat = std::bind(&SVGElement::set_onrepeat, (SVGElement *)this, std::placeholders::_1);
        Onrepeat.set_getter(_getter_onrepeat), Onrepeat.set_setter(_setter_onrepeat);
        Onrepeat.callback_assign(_attr_on_assign[10]), Onrepeat.callback_bind_func(_attr_on_bind[10]), Onrepeat.callback_bind_ptr(_attr_on_bind[10]);
        std::function<const std::string()> _getter_onabort = std::bind(&SVGElement::get_onabort, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onabort = std::bind(&SVGElement::set_onabort, (SVGElement *)this, std::placeholders::_1);
        Onabort.set_getter(_getter_onabort), Onabort.set_setter(_setter_onabort);
        Onabort.callback_assign(_attr_on_assign[11]), Onabort.callback_bind_func(_attr_on_bind[11]), Onabort.callback_bind_ptr(_attr_on_bind[11]);
        std::function<const std::string()> _getter_onerror = std::bind(&SVGElement::get_onerror, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onerror = std::bind(&SVGElement::set_onerror, (SVGElement *)this, std::placeholders::_1);
        Onerror.set_getter(_getter_onerror), Onerror.set_setter(_setter_onerror);
        Onerror.callback_assign(_attr_on_assign[12]), Onerror.callback_bind_func(_attr_on_bind[12]), Onerror.callback_bind_ptr(_attr_on_bind[12]);
        std::function<const std::string()> _getter_onresize = std::bind(&SVGElement::get_onresize, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onresize = std::bind(&SVGElement::set_onresize, (SVGElement *)this, std::placeholders::_1);
        Onresize.set_getter(_getter_onresize), Onresize.set_setter(_setter_onresize);
        Onresize.callback_assign(_attr_on_assign[13]), Onresize.callback_bind_func(_attr_on_bind[13]), Onresize.callback_bind_ptr(_attr_on_bind[13]);
        std::function<const std::string()> _getter_onscroll = std::bind(&SVGElement::get_onscroll, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onscroll = std::bind(&SVGElement::set_onscroll, (SVGElement *)this, std::placeholders::_1);
        Onscroll.set_getter(_getter_onscroll), Onscroll.set_setter(_setter_onscroll);
        Onscroll.callback_assign(_attr_on_assign[14]), Onscroll.callback_bind_func(_attr_on_bind[14]), Onscroll.callback_bind_ptr(_attr_on_bind[14]);
        std::function<const std::string()> _getter_onunload = std::bind(&SVGElement::get_onunload, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onunload = std::bind(&SVGElement::set_onunload, (SVGElement *)this, std::placeholders::_1);
        Onunload.set_getter(_getter_onunload), Onunload.set_setter(_setter_onunload);
        Onunload.callback_assign(_attr_on_assign[15]), Onunload.callback_bind_func(_attr_on_bind[15]), Onunload.callback_bind_ptr(_attr_on_bind[15]);
        std::function<const std::string()> _getter_oncopy = std::bind(&SVGElement::get_oncopy, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_oncopy = std::bind(&SVGElement::set_oncopy, (SVGElement *)this, std::placeholders::_1);
        Oncopy.set_getter(_getter_oncopy), Oncopy.set_setter(_setter_oncopy);
        Oncopy.callback_assign(_attr_on_assign[16]), Oncopy.callback_bind_func(_attr_on_bind[16]), Oncopy.callback_bind_ptr(_attr_on_bind[16]);
        std::function<const std::string()> _getter_oncut = std::bind(&SVGElement::get_oncut, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_oncut = std::bind(&SVGElement::set_oncut, (SVGElement *)this, std::placeholders::_1);
        Oncut.set_getter(_getter_oncut), Oncut.set_setter(_setter_oncut);
        Oncut.callback_assign(_attr_on_assign[17]), Oncut.callback_bind_func(_attr_on_bind[17]), Oncut.callback_bind_ptr(_attr_on_bind[17]);
        std::function<const std::string()> _getter_onpaste = std::bind(&SVGElement::get_onpaste, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onpaste = std::bind(&SVGElement::set_onpaste, (SVGElement *)this, std::placeholders::_1);
        Onpaste.set_getter(_getter_onpaste), Onpaste.set_setter(_setter_onpaste);
        Onpaste.callback_assign(_attr_on_assign[18]), Onpaste.callback_bind_func(_attr_on_bind[18]), Onpaste.callback_bind_ptr(_attr_on_bind[18]);
        std::function<const std::string()> _getter_oncancel = std::bind(&SVGElement::get_oncancel, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_oncancel = std::bind(&SVGElement::set_oncancel, (SVGElement *)this, std::placeholders::_1);
        Oncancel.set_getter(_getter_oncancel), Oncancel.set_setter(_setter_oncancel);
        Oncancel.callback_assign(_attr_on_assign[19]), Oncancel.callback_bind_func(_attr_on_bind[19]), Oncancel.callback_bind_ptr(_attr_on_bind[19]);
        std::function<const std::string()> _getter_oncanplay = std::bind(&SVGElement::get_oncanplay, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_oncanplay = std::bind(&SVGElement::set_oncanplay, (SVGElement *)this, std::placeholders::_1);
        Oncanplay.set_getter(_getter_oncanplay), Oncanplay.set_setter(_setter_oncanplay);
        Oncanplay.callback_assign(_attr_on_assign[20]), Oncanplay.callback_bind_func(_attr_on_bind[20]), Oncanplay.callback_bind_ptr(_attr_on_bind[20]);
        std::function<const std::string()> _getter_oncanplaythrough = std::bind(&SVGElement::get_oncanplaythrough, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_oncanplaythrough = std::bind(&SVGElement::set_oncanplaythrough, (SVGElement *)this, std::placeholders::_1);
        Oncanplaythrough.set_getter(_getter_oncanplaythrough), Oncanplaythrough.set_setter(_setter_oncanplaythrough);
        Oncanplaythrough.callback_assign(_attr_on_assign[21]), Oncanplaythrough.callback_bind_func(_attr_on_bind[21]), Oncanplaythrough.callback_bind_ptr(_attr_on_bind[21]);
        std::function<const std::string()> _getter_onchange = std::bind(&SVGElement::get_onchange, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onchange = std::bind(&SVGElement::set_onchange, (SVGElement *)this, std::placeholders::_1);
        Onchange.set_getter(_getter_onchange), Onchange.set_setter(_setter_onchange);
        Onchange.callback_assign(_attr_on_assign[22]), Onchange.callback_bind_func(_attr_on_bind[22]), Onchange.callback_bind_ptr(_attr_on_bind[22]);
        std::function<const std::string()> _getter_onclick = std::bind(&SVGElement::get_onclick, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onclick = std::bind(&SVGElement::set_onclick, (SVGElement *)this, std::placeholders::_1);
        Onclick.set_getter(_getter_onclick), Onclick.set_setter(_setter_onclick);
        Onclick.callback_assign(_attr_on_assign[23]), Onclick.callback_bind_func(_attr_on_bind[23]), Onclick.callback_bind_ptr(_attr_on_bind[23]);
        std::function<const std::string()> _getter_onclose = std::bind(&SVGElement::get_onclose, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onclose = std::bind(&SVGElement::set_onclose, (SVGElement *)this, std::placeholders::_1);
        Onclose.set_getter(_getter_onclose), Onclose.set_setter(_setter_onclose);
        Onclose.callback_assign(_attr_on_assign[24]), Onclose.callback_bind_func(_attr_on_bind[24]), Onclose.callback_bind_ptr(_attr_on_bind[24]);
        std::function<const std::string()> _getter_oncuechange = std::bind(&SVGElement::get_oncuechange, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_oncuechange = std::bind(&SVGElement::set_oncuechange, (SVGElement *)this, std::placeholders::_1);
        Oncuechange.set_getter(_getter_oncuechange), Oncuechange.set_setter(_setter_oncuechange);
        Oncuechange.callback_assign(_attr_on_assign[25]), Oncuechange.callback_bind_func(_attr_on_bind[25]), Oncuechange.callback_bind_ptr(_attr_on_bind[25]);
        std::function<const std::string()> _getter_ondblclick = std::bind(&SVGElement::get_ondblclick, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondblclick = std::bind(&SVGElement::set_ondblclick, (SVGElement *)this, std::placeholders::_1);
        Ondblclick.set_getter(_getter_ondblclick), Ondblclick.set_setter(_setter_ondblclick);
        Ondblclick.callback_assign(_attr_on_assign[26]), Ondblclick.callback_bind_func(_attr_on_bind[26]), Ondblclick.callback_bind_ptr(_attr_on_bind[26]);
        std::function<const std::string()> _getter_ondrag = std::bind(&SVGElement::get_ondrag, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondrag = std::bind(&SVGElement::set_ondrag, (SVGElement *)this, std::placeholders::_1);
        Ondrag.set_getter(_getter_ondrag), Ondrag.set_setter(_setter_ondrag);
        Ondrag.callback_assign(_attr_on_assign[27]), Ondrag.callback_bind_func(_attr_on_bind[27]), Ondrag.callback_bind_ptr(_attr_on_bind[27]);
        std::function<const std::string()> _getter_ondragend = std::bind(&SVGElement::get_ondragend, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondragend = std::bind(&SVGElement::set_ondragend, (SVGElement *)this, std::placeholders::_1);
        Ondragend.set_getter(_getter_ondragend), Ondragend.set_setter(_setter_ondragend);
        Ondragend.callback_assign(_attr_on_assign[28]), Ondragend.callback_bind_func(_attr_on_bind[28]), Ondragend.callback_bind_ptr(_attr_on_bind[28]);
        std::function<const std::string()> _getter_ondragenter = std::bind(&SVGElement::get_ondragenter, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondragenter = std::bind(&SVGElement::set_ondragenter, (SVGElement *)this, std::placeholders::_1);
        Ondragenter.set_getter(_getter_ondragenter), Ondragenter.set_setter(_setter_ondragenter);
        Ondragenter.callback_assign(_attr_on_assign[29]), Ondragenter.callback_bind_func(_attr_on_bind[29]), Ondragenter.callback_bind_ptr(_attr_on_bind[29]);
        std::function<const std::string()> _getter_ondragleave = std::bind(&SVGElement::get_ondragleave, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondragleave = std::bind(&SVGElement::set_ondragleave, (SVGElement *)this, std::placeholders::_1);
        Ondragleave.set_getter(_getter_ondragleave), Ondragleave.set_setter(_setter_ondragleave);
        Ondragleave.callback_assign(_attr_on_assign[30]), Ondragleave.callback_bind_func(_attr_on_bind[30]), Ondragleave.callback_bind_ptr(_attr_on_bind[30]);
        std::function<const std::string()> _getter_ondragover = std::bind(&SVGElement::get_ondragover, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondragover = std::bind(&SVGElement::set_ondragover, (SVGElement *)this, std::placeholders::_1);
        Ondragover.set_getter(_getter_ondragover), Ondragover.set_setter(_setter_ondragover);
        Ondragover.callback_assign(_attr_on_assign[31]), Ondragover.callback_bind_func(_attr_on_bind[31]), Ondragover.callback_bind_ptr(_attr_on_bind[31]);
        std::function<const std::string()> _getter_ondragstart = std::bind(&SVGElement::get_ondragstart, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondragstart = std::bind(&SVGElement::set_ondragstart, (SVGElement *)this, std::placeholders::_1);
        Ondragstart.set_getter(_getter_ondragstart), Ondragstart.set_setter(_setter_ondragstart);
        Ondragstart.callback_assign(_attr_on_assign[32]), Ondragstart.callback_bind_func(_attr_on_bind[32]), Ondragstart.callback_bind_ptr(_attr_on_bind[32]);
        std::function<const std::string()> _getter_ondrop = std::bind(&SVGElement::get_ondrop, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondrop = std::bind(&SVGElement::set_ondrop, (SVGElement *)this, std::placeholders::_1);
        Ondrop.set_getter(_getter_ondrop), Ondrop.set_setter(_setter_ondrop);
        Ondrop.callback_assign(_attr_on_assign[33]), Ondrop.callback_bind_func(_attr_on_bind[33]), Ondrop.callback_bind_ptr(_attr_on_bind[33]);
        std::function<const std::string()> _getter_ondurationchange = std::bind(&SVGElement::get_ondurationchange, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ondurationchange = std::bind(&SVGElement::set_ondurationchange, (SVGElement *)this, std::placeholders::_1);
        Ondurationchange.set_getter(_getter_ondurationchange), Ondurationchange.set_setter(_setter_ondurationchange);
        Ondurationchange.callback_assign(_attr_on_assign[34]), Ondurationchange.callback_bind_func(_attr_on_bind[34]), Ondurationchange.callback_bind_ptr(_attr_on_bind[34]);
        std::function<const std::string()> _getter_onemptied = std::bind(&SVGElement::get_onemptied, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onemptied = std::bind(&SVGElement::set_onemptied, (SVGElement *)this, std::placeholders::_1);
        Onemptied.set_getter(_getter_onemptied), Onemptied.set_setter(_setter_onemptied);
        Onemptied.callback_assign(_attr_on_assign[35]), Onemptied.callback_bind_func(_attr_on_bind[35]), Onemptied.callback_bind_ptr(_attr_on_bind[35]);
        std::function<const std::string()> _getter_onended = std::bind(&SVGElement::get_onended, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onended = std::bind(&SVGElement::set_onended, (SVGElement *)this, std::placeholders::_1);
        Onended.set_getter(_getter_onended), Onended.set_setter(_setter_onended);
        Onended.callback_assign(_attr_on_assign[36]), Onended.callback_bind_func(_attr_on_bind[36]), Onended.callback_bind_ptr(_attr_on_bind[36]);
        std::function<const std::string()> _getter_onfocus = std::bind(&SVGElement::get_onfocus, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onfocus = std::bind(&SVGElement::set_onfocus, (SVGElement *)this, std::placeholders::_1);
        Onfocus.set_getter(_getter_onfocus), Onfocus.set_setter(_setter_onfocus);
        Onfocus.callback_assign(_attr_on_assign[37]), Onfocus.callback_bind_func(_attr_on_bind[37]), Onfocus.callback_bind_ptr(_attr_on_bind[37]);
        std::function<const std::string()> _getter_oninput = std::bind(&SVGElement::get_oninput, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_oninput = std::bind(&SVGElement::set_oninput, (SVGElement *)this, std::placeholders::_1);
        Oninput.set_getter(_getter_oninput), Oninput.set_setter(_setter_oninput);
        Oninput.callback_assign(_attr_on_assign[38]), Oninput.callback_bind_func(_attr_on_bind[38]), Oninput.callback_bind_ptr(_attr_on_bind[38]);
        std::function<const std::string()> _getter_oninvalid = std::bind(&SVGElement::get_oninvalid, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_oninvalid = std::bind(&SVGElement::set_oninvalid, (SVGElement *)this, std::placeholders::_1);
        Oninvalid.set_getter(_getter_oninvalid), Oninvalid.set_setter(_setter_oninvalid);
        Oninvalid.callback_assign(_attr_on_assign[39]), Oninvalid.callback_bind_func(_attr_on_bind[39]), Oninvalid.callback_bind_ptr(_attr_on_bind[39]);
        std::function<const std::string()> _getter_onkeydown = std::bind(&SVGElement::get_onkeydown, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onkeydown = std::bind(&SVGElement::set_onkeydown, (SVGElement *)this, std::placeholders::_1);
        Onkeydown.set_getter(_getter_onkeydown), Onkeydown.set_setter(_setter_onkeydown);
        Onkeydown.callback_assign(_attr_on_assign[40]), Onkeydown.callback_bind_func(_attr_on_bind[40]), Onkeydown.callback_bind_ptr(_attr_on_bind[40]);
        std::function<const std::string()> _getter_onkeypress = std::bind(&SVGElement::get_onkeypress, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onkeypress = std::bind(&SVGElement::set_onkeypress, (SVGElement *)this, std::placeholders::_1);
        Onkeypress.set_getter(_getter_onkeypress), Onkeypress.set_setter(_setter_onkeypress);
        Onkeypress.callback_assign(_attr_on_assign[41]), Onkeypress.callback_bind_func(_attr_on_bind[41]), Onkeypress.callback_bind_ptr(_attr_on_bind[41]);
        std::function<const std::string()> _getter_onkeyup = std::bind(&SVGElement::get_onkeyup, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onkeyup = std::bind(&SVGElement::set_onkeyup, (SVGElement *)this, std::placeholders::_1);
        Onkeyup.set_getter(_getter_onkeyup), Onkeyup.set_setter(_setter_onkeyup);
        Onkeyup.callback_assign(_attr_on_assign[42]), Onkeyup.callback_bind_func(_attr_on_bind[42]), Onkeyup.callback_bind_ptr(_attr_on_bind[42]);
        std::function<const std::string()> _getter_onload = std::bind(&SVGElement::get_onload, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onload = std::bind(&SVGElement::set_onload, (SVGElement *)this, std::placeholders::_1);
        Onload.set_getter(_getter_onload), Onload.set_setter(_setter_onload);
        Onload.callback_assign(_attr_on_assign[43]), Onload.callback_bind_func(_attr_on_bind[43]), Onload.callback_bind_ptr(_attr_on_bind[43]);
        std::function<const std::string()> _getter_onloadeddata = std::bind(&SVGElement::get_onloadeddata, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onloadeddata = std::bind(&SVGElement::set_onloadeddata, (SVGElement *)this, std::placeholders::_1);
        Onloadeddata.set_getter(_getter_onloadeddata), Onloadeddata.set_setter(_setter_onloadeddata);
        Onloadeddata.callback_assign(_attr_on_assign[44]), Onloadeddata.callback_bind_func(_attr_on_bind[44]), Onloadeddata.callback_bind_ptr(_attr_on_bind[44]);
        std::function<const std::string()> _getter_onloadedmetadata = std::bind(&SVGElement::get_onloadedmetadata, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onloadedmetadata = std::bind(&SVGElement::set_onloadedmetadata, (SVGElement *)this, std::placeholders::_1);
        Onloadedmetadata.set_getter(_getter_onloadedmetadata), Onloadedmetadata.set_setter(_setter_onloadedmetadata);
        Onloadedmetadata.callback_assign(_attr_on_assign[45]), Onloadedmetadata.callback_bind_func(_attr_on_bind[45]), Onloadedmetadata.callback_bind_ptr(_attr_on_bind[45]);
        std::function<const std::string()> _getter_onloadstart = std::bind(&SVGElement::get_onloadstart, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onloadstart = std::bind(&SVGElement::set_onloadstart, (SVGElement *)this, std::placeholders::_1);
        Onloadstart.set_getter(_getter_onloadstart), Onloadstart.set_setter(_setter_onloadstart);
        Onloadstart.callback_assign(_attr_on_assign[46]), Onloadstart.callback_bind_func(_attr_on_bind[46]), Onloadstart.callback_bind_ptr(_attr_on_bind[46]);
        std::function<const std::string()> _getter_onmousedown = std::bind(&SVGElement::get_onmousedown, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onmousedown = std::bind(&SVGElement::set_onmousedown, (SVGElement *)this, std::placeholders::_1);
        Onmousedown.set_getter(_getter_onmousedown), Onmousedown.set_setter(_setter_onmousedown);
        Onmousedown.callback_assign(_attr_on_assign[47]), Onmousedown.callback_bind_func(_attr_on_bind[47]), Onmousedown.callback_bind_ptr(_attr_on_bind[47]);
        std::function<const std::string()> _getter_onmouseenter = std::bind(&SVGElement::get_onmouseenter, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onmouseenter = std::bind(&SVGElement::set_onmouseenter, (SVGElement *)this, std::placeholders::_1);
        Onmouseenter.set_getter(_getter_onmouseenter), Onmouseenter.set_setter(_setter_onmouseenter);
        Onmouseenter.callback_assign(_attr_on_assign[48]), Onmouseenter.callback_bind_func(_attr_on_bind[48]), Onmouseenter.callback_bind_ptr(_attr_on_bind[48]);
        std::function<const std::string()> _getter_onmouseleave = std::bind(&SVGElement::get_onmouseleave, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onmouseleave = std::bind(&SVGElement::set_onmouseleave, (SVGElement *)this, std::placeholders::_1);
        Onmouseleave.set_getter(_getter_onmouseleave), Onmouseleave.set_setter(_setter_onmouseleave);
        Onmouseleave.callback_assign(_attr_on_assign[49]), Onmouseleave.callback_bind_func(_attr_on_bind[49]), Onmouseleave.callback_bind_ptr(_attr_on_bind[49]);
        std::function<const std::string()> _getter_onmousemove = std::bind(&SVGElement::get_onmousemove, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onmousemove = std::bind(&SVGElement::set_onmousemove, (SVGElement *)this, std::placeholders::_1);
        Onmousemove.set_getter(_getter_onmousemove), Onmousemove.set_setter(_setter_onmousemove);
        Onmousemove.callback_assign(_attr_on_assign[50]), Onmousemove.callback_bind_func(_attr_on_bind[50]), Onmousemove.callback_bind_ptr(_attr_on_bind[50]);
        std::function<const std::string()> _getter_onmouseout = std::bind(&SVGElement::get_onmouseout, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onmouseout = std::bind(&SVGElement::set_onmouseout, (SVGElement *)this, std::placeholders::_1);
        Onmouseout.set_getter(_getter_onmouseout), Onmouseout.set_setter(_setter_onmouseout);
        Onmouseout.callback_assign(_attr_on_assign[51]), Onmouseout.callback_bind_func(_attr_on_bind[51]), Onmouseout.callback_bind_ptr(_attr_on_bind[51]);
        std::function<const std::string()> _getter_onmouseover = std::bind(&SVGElement::get_onmouseover, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onmouseover = std::bind(&SVGElement::set_onmouseover, (SVGElement *)this, std::placeholders::_1);
        Onmouseover.set_getter(_getter_onmouseover), Onmouseover.set_setter(_setter_onmouseover);
        Onmouseover.callback_assign(_attr_on_assign[52]), Onmouseover.callback_bind_func(_attr_on_bind[52]), Onmouseover.callback_bind_ptr(_attr_on_bind[52]);
        std::function<const std::string()> _getter_onmouseup = std::bind(&SVGElement::get_onmouseup, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onmouseup = std::bind(&SVGElement::set_onmouseup, (SVGElement *)this, std::placeholders::_1);
        Onmouseup.set_getter(_getter_onmouseup), Onmouseup.set_setter(_setter_onmouseup);
        Onmouseup.callback_assign(_attr_on_assign[53]), Onmouseup.callback_bind_func(_attr_on_bind[53]), Onmouseup.callback_bind_ptr(_attr_on_bind[53]);
        std::function<const std::string()> _getter_onmousewheel = std::bind(&SVGElement::get_onmousewheel, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onmousewheel = std::bind(&SVGElement::set_onmousewheel, (SVGElement *)this, std::placeholders::_1);
        Onmousewheel.set_getter(_getter_onmousewheel), Onmousewheel.set_setter(_setter_onmousewheel);
        Onmousewheel.callback_assign(_attr_on_assign[54]), Onmousewheel.callback_bind_func(_attr_on_bind[54]), Onmousewheel.callback_bind_ptr(_attr_on_bind[54]);
        std::function<const std::string()> _getter_onpause = std::bind(&SVGElement::get_onpause, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onpause = std::bind(&SVGElement::set_onpause, (SVGElement *)this, std::placeholders::_1);
        Onpause.set_getter(_getter_onpause), Onpause.set_setter(_setter_onpause);
        Onpause.callback_assign(_attr_on_assign[55]), Onpause.callback_bind_func(_attr_on_bind[55]), Onpause.callback_bind_ptr(_attr_on_bind[55]);
        std::function<const std::string()> _getter_onplay = std::bind(&SVGElement::get_onplay, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onplay = std::bind(&SVGElement::set_onplay, (SVGElement *)this, std::placeholders::_1);
        Onplay.set_getter(_getter_onplay), Onplay.set_setter(_setter_onplay);
        Onplay.callback_assign(_attr_on_assign[56]), Onplay.callback_bind_func(_attr_on_bind[56]), Onplay.callback_bind_ptr(_attr_on_bind[56]);
        std::function<const std::string()> _getter_onplaying = std::bind(&SVGElement::get_onplaying, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onplaying = std::bind(&SVGElement::set_onplaying, (SVGElement *)this, std::placeholders::_1);
        Onplaying.set_getter(_getter_onplaying), Onplaying.set_setter(_setter_onplaying);
        Onplaying.callback_assign(_attr_on_assign[57]), Onplaying.callback_bind_func(_attr_on_bind[57]), Onplaying.callback_bind_ptr(_attr_on_bind[57]);
        std::function<const std::string()> _getter_onprogress = std::bind(&SVGElement::get_onprogress, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onprogress = std::bind(&SVGElement::set_onprogress, (SVGElement *)this, std::placeholders::_1);
        Onprogress.set_getter(_getter_onprogress), Onprogress.set_setter(_setter_onprogress);
        Onprogress.callback_assign(_attr_on_assign[58]), Onprogress.callback_bind_func(_attr_on_bind[58]), Onprogress.callback_bind_ptr(_attr_on_bind[58]);
        std::function<const std::string()> _getter_onratechange = std::bind(&SVGElement::get_onratechange, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onratechange = std::bind(&SVGElement::set_onratechange, (SVGElement *)this, std::placeholders::_1);
        Onratechange.set_getter(_getter_onratechange), Onratechange.set_setter(_setter_onratechange);
        Onratechange.callback_assign(_attr_on_assign[59]), Onratechange.callback_bind_func(_attr_on_bind[59]), Onratechange.callback_bind_ptr(_attr_on_bind[59]);
        std::function<const std::string()> _getter_onreset = std::bind(&SVGElement::get_onreset, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onreset = std::bind(&SVGElement::set_onreset, (SVGElement *)this, std::placeholders::_1);
        Onreset.set_getter(_getter_onreset), Onreset.set_setter(_setter_onreset);
        Onreset.callback_assign(_attr_on_assign[60]), Onreset.callback_bind_func(_attr_on_bind[60]), Onreset.callback_bind_ptr(_attr_on_bind[60]);
        std::function<const std::string()> _getter_onseeked = std::bind(&SVGElement::get_onseeked, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onseeked = std::bind(&SVGElement::set_onseeked, (SVGElement *)this, std::placeholders::_1);
        Onseeked.set_getter(_getter_onseeked), Onseeked.set_setter(_setter_onseeked);
        Onseeked.callback_assign(_attr_on_assign[61]), Onseeked.callback_bind_func(_attr_on_bind[61]), Onseeked.callback_bind_ptr(_attr_on_bind[61]);
        std::function<const std::string()> _getter_onseeking = std::bind(&SVGElement::get_onseeking, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onseeking = std::bind(&SVGElement::set_onseeking, (SVGElement *)this, std::placeholders::_1);
        Onseeking.set_getter(_getter_onseeking), Onseeking.set_setter(_setter_onseeking);
        Onseeking.callback_assign(_attr_on_assign[62]), Onseeking.callback_bind_func(_attr_on_bind[62]), Onseeking.callback_bind_ptr(_attr_on_bind[62]);
        std::function<const std::string()> _getter_onselect = std::bind(&SVGElement::get_onselect, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onselect = std::bind(&SVGElement::set_onselect, (SVGElement *)this, std::placeholders::_1);
        Onselect.set_getter(_getter_onselect), Onselect.set_setter(_setter_onselect);
        Onselect.callback_assign(_attr_on_assign[63]), Onselect.callback_bind_func(_attr_on_bind[63]), Onselect.callback_bind_ptr(_attr_on_bind[63]);
        std::function<const std::string()> _getter_onshow = std::bind(&SVGElement::get_onshow, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onshow = std::bind(&SVGElement::set_onshow, (SVGElement *)this, std::placeholders::_1);
        Onshow.set_getter(_getter_onshow), Onshow.set_setter(_setter_onshow);
        Onshow.callback_assign(_attr_on_assign[64]), Onshow.callback_bind_func(_attr_on_bind[64]), Onshow.callback_bind_ptr(_attr_on_bind[64]);
        std::function<const std::string()> _getter_onstalled = std::bind(&SVGElement::get_onstalled, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onstalled = std::bind(&SVGElement::set_onstalled, (SVGElement *)this, std::placeholders::_1);
        Onstalled.set_getter(_getter_onstalled), Onstalled.set_setter(_setter_onstalled);
        Onstalled.callback_assign(_attr_on_assign[65]), Onstalled.callback_bind_func(_attr_on_bind[65]), Onstalled.callback_bind_ptr(_attr_on_bind[65]);
        std::function<const std::string()> _getter_onsubmit = std::bind(&SVGElement::get_onsubmit, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onsubmit = std::bind(&SVGElement::set_onsubmit, (SVGElement *)this, std::placeholders::_1);
        Onsubmit.set_getter(_getter_onsubmit), Onsubmit.set_setter(_setter_onsubmit);
        Onsubmit.callback_assign(_attr_on_assign[66]), Onsubmit.callback_bind_func(_attr_on_bind[66]), Onsubmit.callback_bind_ptr(_attr_on_bind[66]);
        std::function<const std::string()> _getter_onsuspend = std::bind(&SVGElement::get_onsuspend, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onsuspend = std::bind(&SVGElement::set_onsuspend, (SVGElement *)this, std::placeholders::_1);
        Onsuspend.set_getter(_getter_onsuspend), Onsuspend.set_setter(_setter_onsuspend);
        Onsuspend.callback_assign(_attr_on_assign[67]), Onsuspend.callback_bind_func(_attr_on_bind[67]), Onsuspend.callback_bind_ptr(_attr_on_bind[67]);
        std::function<const std::string()> _getter_ontimeupdate = std::bind(&SVGElement::get_ontimeupdate, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ontimeupdate = std::bind(&SVGElement::set_ontimeupdate, (SVGElement *)this, std::placeholders::_1);
        Ontimeupdate.set_getter(_getter_ontimeupdate), Ontimeupdate.set_setter(_setter_ontimeupdate);
        Ontimeupdate.callback_assign(_attr_on_assign[68]), Ontimeupdate.callback_bind_func(_attr_on_bind[68]), Ontimeupdate.callback_bind_ptr(_attr_on_bind[68]);
        std::function<const std::string()> _getter_ontoggle = std::bind(&SVGElement::get_ontoggle, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_ontoggle = std::bind(&SVGElement::set_ontoggle, (SVGElement *)this, std::placeholders::_1);
        Ontoggle.set_getter(_getter_ontoggle), Ontoggle.set_setter(_setter_ontoggle);
        Ontoggle.callback_assign(_attr_on_assign[69]), Ontoggle.callback_bind_func(_attr_on_bind[69]), Ontoggle.callback_bind_ptr(_attr_on_bind[69]);
        std::function<const std::string()> _getter_onvolumechange = std::bind(&SVGElement::get_onvolumechange, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onvolumechange = std::bind(&SVGElement::set_onvolumechange, (SVGElement *)this, std::placeholders::_1);
        Onvolumechange.set_getter(_getter_onvolumechange), Onvolumechange.set_setter(_setter_onvolumechange);
        Onvolumechange.callback_assign(_attr_on_assign[70]), Onvolumechange.callback_bind_func(_attr_on_bind[70]), Onvolumechange.callback_bind_ptr(_attr_on_bind[70]);
        std::function<const std::string()> _getter_onwaiting = std::bind(&SVGElement::get_onwaiting, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onwaiting = std::bind(&SVGElement::set_onwaiting, (SVGElement *)this, std::placeholders::_1);
        Onwaiting.set_getter(_getter_onwaiting), Onwaiting.set_setter(_setter_onwaiting);
        Onwaiting.callback_assign(_attr_on_assign[71]), Onwaiting.callback_bind_func(_attr_on_bind[71]), Onwaiting.callback_bind_ptr(_attr_on_bind[71]);
        std::function<const std::string()> _getter_onactivate = std::bind(&SVGElement::get_onactivate, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onactivate = std::bind(&SVGElement::set_onactivate, (SVGElement *)this, std::placeholders::_1);
        Onactivate.set_getter(_getter_onactivate), Onactivate.set_setter(_setter_onactivate);
        Onactivate.callback_assign(_attr_on_assign[72]), Onactivate.callback_bind_func(_attr_on_bind[72]), Onactivate.callback_bind_ptr(_attr_on_bind[72]);
        std::function<const std::string()> _getter_onfocusin = std::bind(&SVGElement::get_onfocusin, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onfocusin = std::bind(&SVGElement::set_onfocusin, (SVGElement *)this, std::placeholders::_1);
        Onfocusin.set_getter(_getter_onfocusin), Onfocusin.set_setter(_setter_onfocusin);
        Onfocusin.callback_assign(_attr_on_assign[73]), Onfocusin.callback_bind_func(_attr_on_bind[73]), Onfocusin.callback_bind_ptr(_attr_on_bind[73]);
        std::function<const std::string()> _getter_onfocusout = std::bind(&SVGElement::get_onfocusout, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_onfocusout = std::bind(&SVGElement::set_onfocusout, (SVGElement *)this, std::placeholders::_1);
        Onfocusout.set_getter(_getter_onfocusout), Onfocusout.set_setter(_setter_onfocusout);
        Onfocusout.callback_assign(_attr_on_assign[74]), Onfocusout.callback_bind_func(_attr_on_bind[74]), Onfocusout.callback_bind_ptr(_attr_on_bind[74]);
        std::function<const std::string()> _getter_alignment_baseline = std::bind(&SVGElement::get_alignment_baseline, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_alignment_baseline = std::bind(&SVGElement::set_alignment_baseline, (SVGElement *)this, std::placeholders::_1);
        AlignmentBaseline.set_getter(_getter_alignment_baseline), AlignmentBaseline.set_setter(_setter_alignment_baseline);
        AlignmentBaseline.callback_assign(_attr_on_assign[75]), AlignmentBaseline.callback_bind_func(_attr_on_bind[75]), AlignmentBaseline.callback_bind_ptr(_attr_on_bind[75]);
        std::function<const std::string()> _getter_baseline_shift = std::bind(&SVGElement::get_baseline_shift, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_baseline_shift = std::bind(&SVGElement::set_baseline_shift, (SVGElement *)this, std::placeholders::_1);
        BaselineShift.set_getter(_getter_baseline_shift), BaselineShift.set_setter(_setter_baseline_shift);
        BaselineShift.callback_assign(_attr_on_assign[76]), BaselineShift.callback_bind_func(_attr_on_bind[76]), BaselineShift.callback_bind_ptr(_attr_on_bind[76]);
        std::function<const std::string()> _getter_clip_path = std::bind(&SVGElement::get_clip_path, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_clip_path = std::bind(&SVGElement::set_clip_path, (SVGElement *)this, std::placeholders::_1);
        ClipPath.set_getter(_getter_clip_path), ClipPath.set_setter(_setter_clip_path);
        ClipPath.callback_assign(_attr_on_assign[77]), ClipPath.callback_bind_func(_attr_on_bind[77]), ClipPath.callback_bind_ptr(_attr_on_bind[77]);
        std::function<const std::string()> _getter_clip_rule = std::bind(&SVGElement::get_clip_rule, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_clip_rule = std::bind(&SVGElement::set_clip_rule, (SVGElement *)this, std::placeholders::_1);
        ClipRule.set_getter(_getter_clip_rule), ClipRule.set_setter(_setter_clip_rule);
        ClipRule.callback_assign(_attr_on_assign[78]), ClipRule.callback_bind_func(_attr_on_bind[78]), ClipRule.callback_bind_ptr(_attr_on_bind[78]);
        std::function<const std::string()> _getter_color = std::bind(&SVGElement::get_color, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_color = std::bind(&SVGElement::set_color, (SVGElement *)this, std::placeholders::_1);
        Color.set_getter(_getter_color), Color.set_setter(_setter_color);
        Color.callback_assign(_attr_on_assign[79]), Color.callback_bind_func(_attr_on_bind[79]), Color.callback_bind_ptr(_attr_on_bind[79]);
        std::function<const std::string()> _getter_color_interpolation = std::bind(&SVGElement::get_color_interpolation, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_color_interpolation = std::bind(&SVGElement::set_color_interpolation, (SVGElement *)this, std::placeholders::_1);
        ColorInterpolation.set_getter(_getter_color_interpolation), ColorInterpolation.set_setter(_setter_color_interpolation);
        ColorInterpolation.callback_assign(_attr_on_assign[80]), ColorInterpolation.callback_bind_func(_attr_on_bind[80]), ColorInterpolation.callback_bind_ptr(_attr_on_bind[80]);
        std::function<const std::string()> _getter_color_interpolation_filters = std::bind(&SVGElement::get_color_interpolation_filters, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_color_interpolation_filters = std::bind(&SVGElement::set_color_interpolation_filters, (SVGElement *)this, std::placeholders::_1);
        ColorInterpolationFilters.set_getter(_getter_color_interpolation_filters), ColorInterpolationFilters.set_setter(_setter_color_interpolation_filters);
        ColorInterpolationFilters.callback_assign(_attr_on_assign[81]), ColorInterpolationFilters.callback_bind_func(_attr_on_bind[81]), ColorInterpolationFilters.callback_bind_ptr(_attr_on_bind[81]);
        std::function<const std::string()> _getter_color_profile = std::bind(&SVGElement::get_color_profile, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_color_profile = std::bind(&SVGElement::set_color_profile, (SVGElement *)this, std::placeholders::_1);
        ColorProfile.set_getter(_getter_color_profile), ColorProfile.set_setter(_setter_color_profile);
        ColorProfile.callback_assign(_attr_on_assign[82]), ColorProfile.callback_bind_func(_attr_on_bind[82]), ColorProfile.callback_bind_ptr(_attr_on_bind[82]);
        std::function<const std::string()> _getter_color_rendering = std::bind(&SVGElement::get_color_rendering, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_color_rendering = std::bind(&SVGElement::set_color_rendering, (SVGElement *)this, std::placeholders::_1);
        ColorRendering.set_getter(_getter_color_rendering), ColorRendering.set_setter(_setter_color_rendering);
        ColorRendering.callback_assign(_attr_on_assign[83]), ColorRendering.callback_bind_func(_attr_on_bind[83]), ColorRendering.callback_bind_ptr(_attr_on_bind[83]);
        std::function<const std::string()> _getter_cursor = std::bind(&SVGElement::get_cursor, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_cursor = std::bind(&SVGElement::set_cursor, (SVGElement *)this, std::placeholders::_1);
        Cursor.set_getter(_getter_cursor), Cursor.set_setter(_setter_cursor);
        Cursor.callback_assign(_attr_on_assign[84]), Cursor.callback_bind_func(_attr_on_bind[84]), Cursor.callback_bind_ptr(_attr_on_bind[84]);
        std::function<const std::string()> _getter_d = std::bind(&SVGElement::get_d, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_d = std::bind(&SVGElement::set_d, (SVGElement *)this, std::placeholders::_1);
        D.set_getter(_getter_d), D.set_setter(_setter_d);
        D.callback_assign(_attr_on_assign[85]), D.callback_bind_func(_attr_on_bind[85]), D.callback_bind_ptr(_attr_on_bind[85]);
        std::function<const std::string()> _getter_direction = std::bind(&SVGElement::get_direction, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_direction = std::bind(&SVGElement::set_direction, (SVGElement *)this, std::placeholders::_1);
        Direction.set_getter(_getter_direction), Direction.set_setter(_setter_direction);
        Direction.callback_assign(_attr_on_assign[86]), Direction.callback_bind_func(_attr_on_bind[86]), Direction.callback_bind_ptr(_attr_on_bind[86]);
        std::function<const std::string()> _getter_display = std::bind(&SVGElement::get_display, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_display = std::bind(&SVGElement::set_display, (SVGElement *)this, std::placeholders::_1);
        Display.set_getter(_getter_display), Display.set_setter(_setter_display);
        Display.callback_assign(_attr_on_assign[87]), Display.callback_bind_func(_attr_on_bind[87]), Display.callback_bind_ptr(_attr_on_bind[87]);
        std::function<const std::string()> _getter_dominant_baseline = std::bind(&SVGElement::get_dominant_baseline, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_dominant_baseline = std::bind(&SVGElement::set_dominant_baseline, (SVGElement *)this, std::placeholders::_1);
        DominantBaseline.set_getter(_getter_dominant_baseline), DominantBaseline.set_setter(_setter_dominant_baseline);
        DominantBaseline.callback_assign(_attr_on_assign[88]), DominantBaseline.callback_bind_func(_attr_on_bind[88]), DominantBaseline.callback_bind_ptr(_attr_on_bind[88]);
        std::function<const std::string()> _getter_enable_background = std::bind(&SVGElement::get_enable_background, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_enable_background = std::bind(&SVGElement::set_enable_background, (SVGElement *)this, std::placeholders::_1);
        EnableBackground.set_getter(_getter_enable_background), EnableBackground.set_setter(_setter_enable_background);
        EnableBackground.callback_assign(_attr_on_assign[89]), EnableBackground.callback_bind_func(_attr_on_bind[89]), EnableBackground.callback_bind_ptr(_attr_on_bind[89]);
        std::function<const std::string()> _getter_fill = std::bind(&SVGElement::get_fill, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_fill = std::bind(&SVGElement::set_fill, (SVGElement *)this, std::placeholders::_1);
        Fill.set_getter(_getter_fill), Fill.set_setter(_setter_fill);
        Fill.callback_assign(_attr_on_assign[90]), Fill.callback_bind_func(_attr_on_bind[90]), Fill.callback_bind_ptr(_attr_on_bind[90]);
        std::function<const std::string()> _getter_fill_opacity = std::bind(&SVGElement::get_fill_opacity, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_fill_opacity = std::bind(&SVGElement::set_fill_opacity, (SVGElement *)this, std::placeholders::_1);
        FillOpacity.set_getter(_getter_fill_opacity), FillOpacity.set_setter(_setter_fill_opacity);
        FillOpacity.callback_assign(_attr_on_assign[91]), FillOpacity.callback_bind_func(_attr_on_bind[91]), FillOpacity.callback_bind_ptr(_attr_on_bind[91]);
        std::function<const std::string()> _getter_fill_rule = std::bind(&SVGElement::get_fill_rule, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_fill_rule = std::bind(&SVGElement::set_fill_rule, (SVGElement *)this, std::placeholders::_1);
        FillRule.set_getter(_getter_fill_rule), FillRule.set_setter(_setter_fill_rule);
        FillRule.callback_assign(_attr_on_assign[92]), FillRule.callback_bind_func(_attr_on_bind[92]), FillRule.callback_bind_ptr(_attr_on_bind[92]);
        std::function<const std::string()> _getter_filter = std::bind(&SVGElement::get_filter, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_filter = std::bind(&SVGElement::set_filter, (SVGElement *)this, std::placeholders::_1);
        Filter.set_getter(_getter_filter), Filter.set_setter(_setter_filter);
        Filter.callback_assign(_attr_on_assign[93]), Filter.callback_bind_func(_attr_on_bind[93]), Filter.callback_bind_ptr(_attr_on_bind[93]);
        std::function<const std::string()> _getter_flood_color = std::bind(&SVGElement::get_flood_color, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_flood_color = std::bind(&SVGElement::set_flood_color, (SVGElement *)this, std::placeholders::_1);
        FloodColor.set_getter(_getter_flood_color), FloodColor.set_setter(_setter_flood_color);
        FloodColor.callback_assign(_attr_on_assign[94]), FloodColor.callback_bind_func(_attr_on_bind[94]), FloodColor.callback_bind_ptr(_attr_on_bind[94]);
        std::function<const std::string()> _getter_flood_opacity = std::bind(&SVGElement::get_flood_opacity, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_flood_opacity = std::bind(&SVGElement::set_flood_opacity, (SVGElement *)this, std::placeholders::_1);
        FloodOpacity.set_getter(_getter_flood_opacity), FloodOpacity.set_setter(_setter_flood_opacity);
        FloodOpacity.callback_assign(_attr_on_assign[95]), FloodOpacity.callback_bind_func(_attr_on_bind[95]), FloodOpacity.callback_bind_ptr(_attr_on_bind[95]);
        std::function<const std::string()> _getter_font_family = std::bind(&SVGElement::get_font_family, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_font_family = std::bind(&SVGElement::set_font_family, (SVGElement *)this, std::placeholders::_1);
        FontFamily.set_getter(_getter_font_family), FontFamily.set_setter(_setter_font_family);
        FontFamily.callback_assign(_attr_on_assign[96]), FontFamily.callback_bind_func(_attr_on_bind[96]), FontFamily.callback_bind_ptr(_attr_on_bind[96]);
        std::function<const std::string()> _getter_font_size = std::bind(&SVGElement::get_font_size, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_font_size = std::bind(&SVGElement::set_font_size, (SVGElement *)this, std::placeholders::_1);
        FontSize.set_getter(_getter_font_size), FontSize.set_setter(_setter_font_size);
        FontSize.callback_assign(_attr_on_assign[97]), FontSize.callback_bind_func(_attr_on_bind[97]), FontSize.callback_bind_ptr(_attr_on_bind[97]);
        std::function<const std::string()> _getter_font_size_adjust = std::bind(&SVGElement::get_font_size_adjust, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_font_size_adjust = std::bind(&SVGElement::set_font_size_adjust, (SVGElement *)this, std::placeholders::_1);
        FontSizeAdjust.set_getter(_getter_font_size_adjust), FontSizeAdjust.set_setter(_setter_font_size_adjust);
        FontSizeAdjust.callback_assign(_attr_on_assign[98]), FontSizeAdjust.callback_bind_func(_attr_on_bind[98]), FontSizeAdjust.callback_bind_ptr(_attr_on_bind[98]);
        std::function<const std::string()> _getter_font_stretch = std::bind(&SVGElement::get_font_stretch, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_font_stretch = std::bind(&SVGElement::set_font_stretch, (SVGElement *)this, std::placeholders::_1);
        FontStretch.set_getter(_getter_font_stretch), FontStretch.set_setter(_setter_font_stretch);
        FontStretch.callback_assign(_attr_on_assign[99]), FontStretch.callback_bind_func(_attr_on_bind[99]), FontStretch.callback_bind_ptr(_attr_on_bind[99]);
        std::function<const std::string()> _getter_font_style = std::bind(&SVGElement::get_font_style, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_font_style = std::bind(&SVGElement::set_font_style, (SVGElement *)this, std::placeholders::_1);
        FontStyle.set_getter(_getter_font_style), FontStyle.set_setter(_setter_font_style);
        FontStyle.callback_assign(_attr_on_assign[100]), FontStyle.callback_bind_func(_attr_on_bind[100]), FontStyle.callback_bind_ptr(_attr_on_bind[100]);
        std::function<const std::string()> _getter_font_variant = std::bind(&SVGElement::get_font_variant, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_font_variant = std::bind(&SVGElement::set_font_variant, (SVGElement *)this, std::placeholders::_1);
        FontVariant.set_getter(_getter_font_variant), FontVariant.set_setter(_setter_font_variant);
        FontVariant.callback_assign(_attr_on_assign[101]), FontVariant.callback_bind_func(_attr_on_bind[101]), FontVariant.callback_bind_ptr(_attr_on_bind[101]);
        std::function<const std::string()> _getter_font_weight = std::bind(&SVGElement::get_font_weight, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_font_weight = std::bind(&SVGElement::set_font_weight, (SVGElement *)this, std::placeholders::_1);
        FontWeight.set_getter(_getter_font_weight), FontWeight.set_setter(_setter_font_weight);
        FontWeight.callback_assign(_attr_on_assign[102]), FontWeight.callback_bind_func(_attr_on_bind[102]), FontWeight.callback_bind_ptr(_attr_on_bind[102]);
        std::function<const std::string()> _getter_glyph_orientation_horizontal = std::bind(&SVGElement::get_glyph_orientation_horizontal, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_glyph_orientation_horizontal = std::bind(&SVGElement::set_glyph_orientation_horizontal, (SVGElement *)this, std::placeholders::_1);
        GlyphOrientationHorizontal.set_getter(_getter_glyph_orientation_horizontal), GlyphOrientationHorizontal.set_setter(_setter_glyph_orientation_horizontal);
        GlyphOrientationHorizontal.callback_assign(_attr_on_assign[103]), GlyphOrientationHorizontal.callback_bind_func(_attr_on_bind[103]), GlyphOrientationHorizontal.callback_bind_ptr(_attr_on_bind[103]);
        std::function<const std::string()> _getter_glyph_orientation_vertical = std::bind(&SVGElement::get_glyph_orientation_vertical, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_glyph_orientation_vertical = std::bind(&SVGElement::set_glyph_orientation_vertical, (SVGElement *)this, std::placeholders::_1);
        GlyphOrientationVertical.set_getter(_getter_glyph_orientation_vertical), GlyphOrientationVertical.set_setter(_setter_glyph_orientation_vertical);
        GlyphOrientationVertical.callback_assign(_attr_on_assign[104]), GlyphOrientationVertical.callback_bind_func(_attr_on_bind[104]), GlyphOrientationVertical.callback_bind_ptr(_attr_on_bind[104]);
        std::function<const std::string()> _getter_image_rendering = std::bind(&SVGElement::get_image_rendering, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_image_rendering = std::bind(&SVGElement::set_image_rendering, (SVGElement *)this, std::placeholders::_1);
        ImageRendering.set_getter(_getter_image_rendering), ImageRendering.set_setter(_setter_image_rendering);
        ImageRendering.callback_assign(_attr_on_assign[105]), ImageRendering.callback_bind_func(_attr_on_bind[105]), ImageRendering.callback_bind_ptr(_attr_on_bind[105]);
        std::function<const std::string()> _getter_kerning = std::bind(&SVGElement::get_kerning, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_kerning = std::bind(&SVGElement::set_kerning, (SVGElement *)this, std::placeholders::_1);
        Kerning.set_getter(_getter_kerning), Kerning.set_setter(_setter_kerning);
        Kerning.callback_assign(_attr_on_assign[106]), Kerning.callback_bind_func(_attr_on_bind[106]), Kerning.callback_bind_ptr(_attr_on_bind[106]);
        std::function<const std::string()> _getter_letter_spacing = std::bind(&SVGElement::get_letter_spacing, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_letter_spacing = std::bind(&SVGElement::set_letter_spacing, (SVGElement *)this, std::placeholders::_1);
        LetterSpacing.set_getter(_getter_letter_spacing), LetterSpacing.set_setter(_setter_letter_spacing);
        LetterSpacing.callback_assign(_attr_on_assign[107]), LetterSpacing.callback_bind_func(_attr_on_bind[107]), LetterSpacing.callback_bind_ptr(_attr_on_bind[107]);
        std::function<const std::string()> _getter_lighting_color = std::bind(&SVGElement::get_lighting_color, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_lighting_color = std::bind(&SVGElement::set_lighting_color, (SVGElement *)this, std::placeholders::_1);
        LightingColor.set_getter(_getter_lighting_color), LightingColor.set_setter(_setter_lighting_color);
        LightingColor.callback_assign(_attr_on_assign[108]), LightingColor.callback_bind_func(_attr_on_bind[108]), LightingColor.callback_bind_ptr(_attr_on_bind[108]);
        std::function<const std::string()> _getter_marker_end = std::bind(&SVGElement::get_marker_end, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_marker_end = std::bind(&SVGElement::set_marker_end, (SVGElement *)this, std::placeholders::_1);
        MarkerEnd.set_getter(_getter_marker_end), MarkerEnd.set_setter(_setter_marker_end);
        MarkerEnd.callback_assign(_attr_on_assign[109]), MarkerEnd.callback_bind_func(_attr_on_bind[109]), MarkerEnd.callback_bind_ptr(_attr_on_bind[109]);
        std::function<const std::string()> _getter_marker_mid = std::bind(&SVGElement::get_marker_mid, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_marker_mid = std::bind(&SVGElement::set_marker_mid, (SVGElement *)this, std::placeholders::_1);
        MarkerMid.set_getter(_getter_marker_mid), MarkerMid.set_setter(_setter_marker_mid);
        MarkerMid.callback_assign(_attr_on_assign[110]), MarkerMid.callback_bind_func(_attr_on_bind[110]), MarkerMid.callback_bind_ptr(_attr_on_bind[110]);
        std::function<const std::string()> _getter_marker_start = std::bind(&SVGElement::get_marker_start, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_marker_start = std::bind(&SVGElement::set_marker_start, (SVGElement *)this, std::placeholders::_1);
        MarkerStart.set_getter(_getter_marker_start), MarkerStart.set_setter(_setter_marker_start);
        MarkerStart.callback_assign(_attr_on_assign[111]), MarkerStart.callback_bind_func(_attr_on_bind[111]), MarkerStart.callback_bind_ptr(_attr_on_bind[111]);
        std::function<const std::string()> _getter_mask = std::bind(&SVGElement::get_mask, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_mask = std::bind(&SVGElement::set_mask, (SVGElement *)this, std::placeholders::_1);
        Mask.set_getter(_getter_mask), Mask.set_setter(_setter_mask);
        Mask.callback_assign(_attr_on_assign[112]), Mask.callback_bind_func(_attr_on_bind[112]), Mask.callback_bind_ptr(_attr_on_bind[112]);
        std::function<const std::string()> _getter_opacity = std::bind(&SVGElement::get_opacity, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_opacity = std::bind(&SVGElement::set_opacity, (SVGElement *)this, std::placeholders::_1);
        Opacity.set_getter(_getter_opacity), Opacity.set_setter(_setter_opacity);
        Opacity.callback_assign(_attr_on_assign[113]), Opacity.callback_bind_func(_attr_on_bind[113]), Opacity.callback_bind_ptr(_attr_on_bind[113]);
        std::function<const std::string()> _getter_overflow = std::bind(&SVGElement::get_overflow, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_overflow = std::bind(&SVGElement::set_overflow, (SVGElement *)this, std::placeholders::_1);
        Overflow.set_getter(_getter_overflow), Overflow.set_setter(_setter_overflow);
        Overflow.callback_assign(_attr_on_assign[114]), Overflow.callback_bind_func(_attr_on_bind[114]), Overflow.callback_bind_ptr(_attr_on_bind[114]);
        std::function<const std::string()> _getter_pointer_events = std::bind(&SVGElement::get_pointer_events, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_pointer_events = std::bind(&SVGElement::set_pointer_events, (SVGElement *)this, std::placeholders::_1);
        PointerEvents.set_getter(_getter_pointer_events), PointerEvents.set_setter(_setter_pointer_events);
        PointerEvents.callback_assign(_attr_on_assign[115]), PointerEvents.callback_bind_func(_attr_on_bind[115]), PointerEvents.callback_bind_ptr(_attr_on_bind[115]);
        std::function<const std::string()> _getter_shape_rendering = std::bind(&SVGElement::get_shape_rendering, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_shape_rendering = std::bind(&SVGElement::set_shape_rendering, (SVGElement *)this, std::placeholders::_1);
        ShapeRendering.set_getter(_getter_shape_rendering), ShapeRendering.set_setter(_setter_shape_rendering);
        ShapeRendering.callback_assign(_attr_on_assign[116]), ShapeRendering.callback_bind_func(_attr_on_bind[116]), ShapeRendering.callback_bind_ptr(_attr_on_bind[116]);
        std::function<const std::string()> _getter_solid_color = std::bind(&SVGElement::get_solid_color, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_solid_color = std::bind(&SVGElement::set_solid_color, (SVGElement *)this, std::placeholders::_1);
        SolidColor.set_getter(_getter_solid_color), SolidColor.set_setter(_setter_solid_color);
        SolidColor.callback_assign(_attr_on_assign[117]), SolidColor.callback_bind_func(_attr_on_bind[117]), SolidColor.callback_bind_ptr(_attr_on_bind[117]);
        std::function<const std::string()> _getter_solid_opacity = std::bind(&SVGElement::get_solid_opacity, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_solid_opacity = std::bind(&SVGElement::set_solid_opacity, (SVGElement *)this, std::placeholders::_1);
        SolidOpacity.set_getter(_getter_solid_opacity), SolidOpacity.set_setter(_setter_solid_opacity);
        SolidOpacity.callback_assign(_attr_on_assign[118]), SolidOpacity.callback_bind_func(_attr_on_bind[118]), SolidOpacity.callback_bind_ptr(_attr_on_bind[118]);
        std::function<const std::string()> _getter_stop_color = std::bind(&SVGElement::get_stop_color, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stop_color = std::bind(&SVGElement::set_stop_color, (SVGElement *)this, std::placeholders::_1);
        StopColor.set_getter(_getter_stop_color), StopColor.set_setter(_setter_stop_color);
        StopColor.callback_assign(_attr_on_assign[119]), StopColor.callback_bind_func(_attr_on_bind[119]), StopColor.callback_bind_ptr(_attr_on_bind[119]);
        std::function<const std::string()> _getter_stop_opacity = std::bind(&SVGElement::get_stop_opacity, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stop_opacity = std::bind(&SVGElement::set_stop_opacity, (SVGElement *)this, std::placeholders::_1);
        StopOpacity.set_getter(_getter_stop_opacity), StopOpacity.set_setter(_setter_stop_opacity);
        StopOpacity.callback_assign(_attr_on_assign[120]), StopOpacity.callback_bind_func(_attr_on_bind[120]), StopOpacity.callback_bind_ptr(_attr_on_bind[120]);
        std::function<const std::string()> _getter_stroke = std::bind(&SVGElement::get_stroke, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stroke = std::bind(&SVGElement::set_stroke, (SVGElement *)this, std::placeholders::_1);
        Stroke.set_getter(_getter_stroke), Stroke.set_setter(_setter_stroke);
        Stroke.callback_assign(_attr_on_assign[121]), Stroke.callback_bind_func(_attr_on_bind[121]), Stroke.callback_bind_ptr(_attr_on_bind[121]);
        std::function<const std::string()> _getter_stroke_dasharray = std::bind(&SVGElement::get_stroke_dasharray, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stroke_dasharray = std::bind(&SVGElement::set_stroke_dasharray, (SVGElement *)this, std::placeholders::_1);
        StrokeDasharray.set_getter(_getter_stroke_dasharray), StrokeDasharray.set_setter(_setter_stroke_dasharray);
        StrokeDasharray.callback_assign(_attr_on_assign[122]), StrokeDasharray.callback_bind_func(_attr_on_bind[122]), StrokeDasharray.callback_bind_ptr(_attr_on_bind[122]);
        std::function<const std::string()> _getter_stroke_dashoffset = std::bind(&SVGElement::get_stroke_dashoffset, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stroke_dashoffset = std::bind(&SVGElement::set_stroke_dashoffset, (SVGElement *)this, std::placeholders::_1);
        StrokeDashoffset.set_getter(_getter_stroke_dashoffset), StrokeDashoffset.set_setter(_setter_stroke_dashoffset);
        StrokeDashoffset.callback_assign(_attr_on_assign[123]), StrokeDashoffset.callback_bind_func(_attr_on_bind[123]), StrokeDashoffset.callback_bind_ptr(_attr_on_bind[123]);
        std::function<const std::string()> _getter_stroke_linecap = std::bind(&SVGElement::get_stroke_linecap, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stroke_linecap = std::bind(&SVGElement::set_stroke_linecap, (SVGElement *)this, std::placeholders::_1);
        StrokeLinecap.set_getter(_getter_stroke_linecap), StrokeLinecap.set_setter(_setter_stroke_linecap);
        StrokeLinecap.callback_assign(_attr_on_assign[124]), StrokeLinecap.callback_bind_func(_attr_on_bind[124]), StrokeLinecap.callback_bind_ptr(_attr_on_bind[124]);
        std::function<const std::string()> _getter_stroke_linejoin = std::bind(&SVGElement::get_stroke_linejoin, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stroke_linejoin = std::bind(&SVGElement::set_stroke_linejoin, (SVGElement *)this, std::placeholders::_1);
        StrokeLinejoin.set_getter(_getter_stroke_linejoin), StrokeLinejoin.set_setter(_setter_stroke_linejoin);
        StrokeLinejoin.callback_assign(_attr_on_assign[125]), StrokeLinejoin.callback_bind_func(_attr_on_bind[125]), StrokeLinejoin.callback_bind_ptr(_attr_on_bind[125]);
        std::function<const std::string()> _getter_stroke_miterlimit = std::bind(&SVGElement::get_stroke_miterlimit, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stroke_miterlimit = std::bind(&SVGElement::set_stroke_miterlimit, (SVGElement *)this, std::placeholders::_1);
        StrokeMiterlimit.set_getter(_getter_stroke_miterlimit), StrokeMiterlimit.set_setter(_setter_stroke_miterlimit);
        StrokeMiterlimit.callback_assign(_attr_on_assign[126]), StrokeMiterlimit.callback_bind_func(_attr_on_bind[126]), StrokeMiterlimit.callback_bind_ptr(_attr_on_bind[126]);
        std::function<const std::string()> _getter_stroke_opacity = std::bind(&SVGElement::get_stroke_opacity, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stroke_opacity = std::bind(&SVGElement::set_stroke_opacity, (SVGElement *)this, std::placeholders::_1);
        StrokeOpacity.set_getter(_getter_stroke_opacity), StrokeOpacity.set_setter(_setter_stroke_opacity);
        StrokeOpacity.callback_assign(_attr_on_assign[127]), StrokeOpacity.callback_bind_func(_attr_on_bind[127]), StrokeOpacity.callback_bind_ptr(_attr_on_bind[127]);
        std::function<const std::string()> _getter_stroke_width = std::bind(&SVGElement::get_stroke_width, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_stroke_width = std::bind(&SVGElement::set_stroke_width, (SVGElement *)this, std::placeholders::_1);
        StrokeWidth.set_getter(_getter_stroke_width), StrokeWidth.set_setter(_setter_stroke_width);
        StrokeWidth.callback_assign(_attr_on_assign[128]), StrokeWidth.callback_bind_func(_attr_on_bind[128]), StrokeWidth.callback_bind_ptr(_attr_on_bind[128]);
        std::function<const std::string()> _getter_text_anchor = std::bind(&SVGElement::get_text_anchor, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_text_anchor = std::bind(&SVGElement::set_text_anchor, (SVGElement *)this, std::placeholders::_1);
        TextAnchor.set_getter(_getter_text_anchor), TextAnchor.set_setter(_setter_text_anchor);
        TextAnchor.callback_assign(_attr_on_assign[129]), TextAnchor.callback_bind_func(_attr_on_bind[129]), TextAnchor.callback_bind_ptr(_attr_on_bind[129]);
        std::function<const std::string()> _getter_text_decoration = std::bind(&SVGElement::get_text_decoration, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_text_decoration = std::bind(&SVGElement::set_text_decoration, (SVGElement *)this, std::placeholders::_1);
        TextDecoration.set_getter(_getter_text_decoration), TextDecoration.set_setter(_setter_text_decoration);
        TextDecoration.callback_assign(_attr_on_assign[130]), TextDecoration.callback_bind_func(_attr_on_bind[130]), TextDecoration.callback_bind_ptr(_attr_on_bind[130]);
        std::function<const std::string()> _getter_text_rendering = std::bind(&SVGElement::get_text_rendering, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_text_rendering = std::bind(&SVGElement::set_text_rendering, (SVGElement *)this, std::placeholders::_1);
        TextRendering.set_getter(_getter_text_rendering), TextRendering.set_setter(_setter_text_rendering);
        TextRendering.callback_assign(_attr_on_assign[131]), TextRendering.callback_bind_func(_attr_on_bind[131]), TextRendering.callback_bind_ptr(_attr_on_bind[131]);
        std::function<const std::string()> _getter_transform = std::bind(&SVGElement::get_transform, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_transform = std::bind(&SVGElement::set_transform, (SVGElement *)this, std::placeholders::_1);
        Transform.set_getter(_getter_transform), Transform.set_setter(_setter_transform);
        Transform.callback_assign(_attr_on_assign[132]), Transform.callback_bind_func(_attr_on_bind[132]), Transform.callback_bind_ptr(_attr_on_bind[132]);
        std::function<const std::string()> _getter_unicode_bidi = std::bind(&SVGElement::get_unicode_bidi, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_unicode_bidi = std::bind(&SVGElement::set_unicode_bidi, (SVGElement *)this, std::placeholders::_1);
        UnicodeBidi.set_getter(_getter_unicode_bidi), UnicodeBidi.set_setter(_setter_unicode_bidi);
        UnicodeBidi.callback_assign(_attr_on_assign[133]), UnicodeBidi.callback_bind_func(_attr_on_bind[133]), UnicodeBidi.callback_bind_ptr(_attr_on_bind[133]);
        std::function<const std::string()> _getter_vector_effect = std::bind(&SVGElement::get_vector_effect, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_vector_effect = std::bind(&SVGElement::set_vector_effect, (SVGElement *)this, std::placeholders::_1);
        VectorEffect.set_getter(_getter_vector_effect), VectorEffect.set_setter(_setter_vector_effect);
        VectorEffect.callback_assign(_attr_on_assign[134]), VectorEffect.callback_bind_func(_attr_on_bind[134]), VectorEffect.callback_bind_ptr(_attr_on_bind[134]);
        std::function<const std::string()> _getter_visibility = std::bind(&SVGElement::get_visibility, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_visibility = std::bind(&SVGElement::set_visibility, (SVGElement *)this, std::placeholders::_1);
        Visibility.set_getter(_getter_visibility), Visibility.set_setter(_setter_visibility);
        Visibility.callback_assign(_attr_on_assign[135]), Visibility.callback_bind_func(_attr_on_bind[135]), Visibility.callback_bind_ptr(_attr_on_bind[135]);
        std::function<const std::string()> _getter_word_spacing = std::bind(&SVGElement::get_word_spacing, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_word_spacing = std::bind(&SVGElement::set_word_spacing, (SVGElement *)this, std::placeholders::_1);
        WordSpacing.set_getter(_getter_word_spacing), WordSpacing.set_setter(_setter_word_spacing);
        WordSpacing.callback_assign(_attr_on_assign[136]), WordSpacing.callback_bind_func(_attr_on_bind[136]), WordSpacing.callback_bind_ptr(_attr_on_bind[136]);
        std::function<const std::string()> _getter_writing_mode = std::bind(&SVGElement::get_writing_mode, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_writing_mode = std::bind(&SVGElement::set_writing_mode, (SVGElement *)this, std::placeholders::_1);
        WritingMode.set_getter(_getter_writing_mode), WritingMode.set_setter(_setter_writing_mode);
        WritingMode.callback_assign(_attr_on_assign[137]), WritingMode.callback_bind_func(_attr_on_bind[137]), WritingMode.callback_bind_ptr(_attr_on_bind[137]);

        std::function<const std::string()> _getter_raw_html = std::bind(&SVGElement::get_raw_HTML, (SVGElement *)this);
        std::function<void(const std::string &)> _setter_raw_html = std::bind(&SVGElement::set_raw_HTML, (SVGElement *)this, std::placeholders::_1);
        RawHTML.set_getter(_getter_raw_html), RawHTML.set_setter(_setter_raw_html);
    }

    const std::string SVGIElement::get_tag() const {
        return SVGElement::get_tag();
    }

    const std::string SVGIElement::inner_SVG() const {
        return SVGElement::inner_SVG();
    }
    void SVGIElement::add(const std::shared_ptr<SVGIElement> &element, int index) {
        if (index == -1) _inner_elements_commit.push_back(element);
        else _inner_elements_commit.insert(_inner_elements_commit.begin() + index, element);
    }
    void SVGIElement::remove(const std::shared_ptr<SVGIElement> &element, bool remove_all) {
        bool success;
        std::vector<std::shared_ptr<SVGIElement>> removed;
        _inner_elements_commit.erase(std::remove_if(_inner_elements_commit.begin(), _inner_elements_commit.end(),
                                [&](const std::shared_ptr<SVGIElement>& _inner_element) { 
                                    if (success && !remove_all) return false;
                                    if (_inner_element->get_outer_hash() == element->get_outer_hash()) {
                                        success = true;
                                        removed.push_back(_inner_element);
                                        return true;
                                    }
                                    return false;
                                }), _inner_elements_commit.end());
        success = false;
        for (auto &p : removed) p->_parent_element_commit = std::weak_ptr<SVGIElement>();
    }
    void SVGIElement::remove(int index) {
        _inner_elements_commit[index]->_parent_element = std::weak_ptr<SVGIElement>();
        _inner_elements_commit.erase(_inner_elements_commit.begin() + index);
    }
    std::shared_ptr<SVGIElement> SVGIElement::child(int index) const {
        return _inner_elements_commit[index];
    }
    const std::vector<std::shared_ptr<SVGIElement>> SVGIElement::children() const {
        return _inner_elements_commit;
    }
    void SVGIElement::children(const std::vector<std::shared_ptr<SVGIElement>> &elements) {
        while (_inner_elements_commit.size() > 0) remove(0);
        for (auto p : elements) add(p);
    }

    const std::string SVGIElement::outer_SVG() const {
        return SVGElement::outer_SVG();
    }
    const HASH_CODE SVGIElement::hash() const {
        return SVGElement::get_outer_hash();
    }

    const std::string SVGIElement::commit() {
        std::stringstream ss;

        _updated_raw_html = get_raw_HTML() != RawHTML.get_commit();
        RawHTML.commit();
        if (get_raw_HTML() != STR_NULL) return "";

        // attribute differ
        for (auto &i : bound) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        for (auto &i : modified) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        modified.clear();
        
        // recursion
        std::vector<std::string> changed;
        for (auto &p : _inner_elements_commit) changed.push_back(p->commit());
        // extract change relation
        std::vector<int> removal;
        std::vector<int> addition;
        std::vector<std::pair<int, int>> unchanged;
        inner_differ_commit(removal, addition, unchanged);
        // remove
        int m = _inner_elements_commit.size(), n = _inner_elements_last.size();
        int *indices = new int[m], *removed = new int[n];
        std::fill(indices, indices + m, 0); std::fill(removed, removed + n, 0);
        for (auto &r : removal) removed[r] = 1;
        for (int i = 1; i < n; i++) removed[i] += removed[i - 1];
        for (auto &r : removal) ss << "remove " << r - (r > 0 ? removed[r - 1] : 0) << std::endl;
        // append
        for (auto &a : addition) {
            auto svg = _inner_elements_commit[a]->outer_SVG();
            ss << "append " << svg.size() << std::endl << svg << std::endl;
        }
        // changed
        for (auto &c : unchanged) {
            auto &a = c.first; auto &b = c.second;
            auto &s = changed[a];
            if (s == STR_NULL) continue;
            ss << "child " << b - removed[b] << std::endl;
            ss << s;
            ss << "parent" << std::endl;
        }
        // sort
        for (auto &c : unchanged) {
            auto &a = c.first; auto &b = c.second;
            indices[b - removed[b]] = a;
        }
        for (int i = 0; i < addition.size(); i++) {
            auto &a = addition[i];
            indices[unchanged.size() + i] = a;
        }
        bool ordered = true;
        for (int i = 0; i < m && ordered; i++) if (indices[i] != i) ordered = false;
        if (!ordered) {
            ss << "sort \"";
            for (int i = 0; i < m; i++) {
                ss << indices[i];
                if (i < m - 1) ss << ",";
            }
            ss << "\"" << std::endl;
        }
        delete[] removed; delete[] indices;

        // commit inner changes
        _inner_elements_last.clear();
        SVGElement::set_inner_elements({});
        for (auto &p : _inner_elements_commit) {
            if (p->_updated_raw_html) p->_updated_raw_html = false;
            _inner_elements_last.push_back(p);
            SVGElement::add_inner_element(p);
        }

        return ss.str();
    }
    void SVGIElement::inner_differ_commit(std::vector<int> &removal,
            std::vector<int> &addition,
            std::vector<std::pair<int, int>> &unchanged) const {
        std::function<const std::string(const std::shared_ptr<SVGIElement> &)> get_tag;
        int _uc;
        get_tag = [&](const std::shared_ptr<SVGIElement> &x){
            if (x->_updated_raw_html) return std::string("#") + std::to_string(_uc++);
            return std::string(x->get_tag());
        };
        std::unordered_map<std::string, std::set<_i_el_idx>> tags_map;
        std::set<_i_el_idx> A, B;
        int c = 0;
        for (auto &a : _inner_elements_commit) A.insert({a, c++}); c = 0;
        for (auto &b : _inner_elements_last) tags_map[get_tag(b)].insert({b, c}), B.insert({b, c++});

        c = 0;
        for (auto &_a : _inner_elements_commit) { // with outer hash equal
            auto &tag  = get_tag(_a);
            _i_el_idx a = { _a, c++ };
            if (!A.count(a) || !tags_map.count(tag)) continue;
            _i_el_idx match = { nullptr, -1 };
            for (auto &b : tags_map[tag]) {
                if (b.ptr->get_outer_hash() == a.ptr->get_outer_hash()) {
                    match = b;
                    break;
                }
            }
            if (match.idx >= 0) {
                tags_map[tag].erase(match);
                A.erase(a), B.erase(match);
                unchanged.push_back({a.idx, match.idx});
            }
        }
        c = 0;
        for (auto &_a : _inner_elements_commit) { // with inner hash equal
            auto &tag  = get_tag(_a);
            _i_el_idx a = { _a, c++ };
            if (!A.count(a) || !tags_map.count(tag)) continue;
            _i_el_idx match = { nullptr, -1 };
            for (auto &b : tags_map[tag]) {
                if (b.ptr->get_inner_hash() == a.ptr->get_inner_hash()) {
                    match = b;
                    break;
                }
            }
            if (match.idx >= 0) {
                tags_map[tag].erase(match);
                A.erase(a), B.erase(match);
                unchanged.push_back({a.idx, match.idx});
            }
        }
        c = 0;
        for (auto &_a : _inner_elements_commit) { // with attribute hash equal
            auto &tag  = get_tag(_a);
            _i_el_idx a = { _a, c++ };
            if (!A.count(a) || !tags_map.count(tag)) continue;
            _i_el_idx match = { nullptr, -1 };
            for (auto &b : tags_map[tag]) {
                if (b.ptr->get_attribute_hash() == a.ptr->get_attribute_hash()) {
                    match = b;
                    break;
                }
            }
            if (match.idx >= 0) {
                tags_map[tag].erase(match);
                A.erase(a), B.erase(match);
                unchanged.push_back({a.idx, match.idx});
            }
        }
        c = 0;
        for (auto &_a : _inner_elements_commit) { // with tag equal
            auto &tag  = get_tag(_a);
            _i_el_idx a = { _a, c++ };
            if (!A.count(a) || !tags_map.count(tag) || tags_map[tag].size() == 0) continue;
            _i_el_idx match = *tags_map[tag].begin();
            tags_map[tag].erase(match);
            A.erase(a), B.erase(match);
            unchanged.push_back({a.idx, match.idx});
        }
        for (auto &a : A) addition.push_back(a.idx);
        for (auto &b : B) removal.push_back(b.idx);
    }
    std::shared_ptr<SVGElement> SVGIElement::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        *cloned = *this;
        return cloned;
    }
    std::shared_ptr<SVGIElement> SVGIElement::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIElement>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIElement::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIElement &SVGIElement::operator=(const SVGIElement &element) {
        SVGElement::operator=(element);
        Id = element.Id;
        Lang = element.Lang;
        Tabindex = element.Tabindex;
        XmlBase = element.XmlBase;
        XmlLang = element.XmlLang;
        XmlSpace = element.XmlSpace;
        Class = element.Class;
        Style = element.Style;
        Onbegin = element.Onbegin;
        Onend = element.Onend;
        Onrepeat = element.Onrepeat;
        Onabort = element.Onabort;
        Onerror = element.Onerror;
        Onresize = element.Onresize;
        Onscroll = element.Onscroll;
        Onunload = element.Onunload;
        Oncopy = element.Oncopy;
        Oncut = element.Oncut;
        Onpaste = element.Onpaste;
        Oncancel = element.Oncancel;
        Oncanplay = element.Oncanplay;
        Oncanplaythrough = element.Oncanplaythrough;
        Onchange = element.Onchange;
        Onclick = element.Onclick;
        Onclose = element.Onclose;
        Oncuechange = element.Oncuechange;
        Ondblclick = element.Ondblclick;
        Ondrag = element.Ondrag;
        Ondragend = element.Ondragend;
        Ondragenter = element.Ondragenter;
        Ondragleave = element.Ondragleave;
        Ondragover = element.Ondragover;
        Ondragstart = element.Ondragstart;
        Ondrop = element.Ondrop;
        Ondurationchange = element.Ondurationchange;
        Onemptied = element.Onemptied;
        Onended = element.Onended;
        Onfocus = element.Onfocus;
        Oninput = element.Oninput;
        Oninvalid = element.Oninvalid;
        Onkeydown = element.Onkeydown;
        Onkeypress = element.Onkeypress;
        Onkeyup = element.Onkeyup;
        Onload = element.Onload;
        Onloadeddata = element.Onloadeddata;
        Onloadedmetadata = element.Onloadedmetadata;
        Onloadstart = element.Onloadstart;
        Onmousedown = element.Onmousedown;
        Onmouseenter = element.Onmouseenter;
        Onmouseleave = element.Onmouseleave;
        Onmousemove = element.Onmousemove;
        Onmouseout = element.Onmouseout;
        Onmouseover = element.Onmouseover;
        Onmouseup = element.Onmouseup;
        Onmousewheel = element.Onmousewheel;
        Onpause = element.Onpause;
        Onplay = element.Onplay;
        Onplaying = element.Onplaying;
        Onprogress = element.Onprogress;
        Onratechange = element.Onratechange;
        Onreset = element.Onreset;
        Onseeked = element.Onseeked;
        Onseeking = element.Onseeking;
        Onselect = element.Onselect;
        Onshow = element.Onshow;
        Onstalled = element.Onstalled;
        Onsubmit = element.Onsubmit;
        Onsuspend = element.Onsuspend;
        Ontimeupdate = element.Ontimeupdate;
        Ontoggle = element.Ontoggle;
        Onvolumechange = element.Onvolumechange;
        Onwaiting = element.Onwaiting;
        Onactivate = element.Onactivate;
        Onfocusin = element.Onfocusin;
        Onfocusout = element.Onfocusout;
        AlignmentBaseline = element.AlignmentBaseline;
        BaselineShift = element.BaselineShift;
        ClipPath = element.ClipPath;
        ClipRule = element.ClipRule;
        Color = element.Color;
        ColorInterpolation = element.ColorInterpolation;
        ColorInterpolationFilters = element.ColorInterpolationFilters;
        ColorProfile = element.ColorProfile;
        ColorRendering = element.ColorRendering;
        Cursor = element.Cursor;
        D = element.D;
        Direction = element.Direction;
        Display = element.Display;
        DominantBaseline = element.DominantBaseline;
        EnableBackground = element.EnableBackground;
        Fill = element.Fill;
        FillOpacity = element.FillOpacity;
        FillRule = element.FillRule;
        Filter = element.Filter;
        FloodColor = element.FloodColor;
        FloodOpacity = element.FloodOpacity;
        FontFamily = element.FontFamily;
        FontSize = element.FontSize;
        FontSizeAdjust = element.FontSizeAdjust;
        FontStretch = element.FontStretch;
        FontStyle = element.FontStyle;
        FontVariant = element.FontVariant;
        FontWeight = element.FontWeight;
        GlyphOrientationHorizontal = element.GlyphOrientationHorizontal;
        GlyphOrientationVertical = element.GlyphOrientationVertical;
        ImageRendering = element.ImageRendering;
        Kerning = element.Kerning;
        LetterSpacing = element.LetterSpacing;
        LightingColor = element.LightingColor;
        MarkerEnd = element.MarkerEnd;
        MarkerMid = element.MarkerMid;
        MarkerStart = element.MarkerStart;
        Mask = element.Mask;
        Opacity = element.Opacity;
        Overflow = element.Overflow;
        PointerEvents = element.PointerEvents;
        ShapeRendering = element.ShapeRendering;
        SolidColor = element.SolidColor;
        SolidOpacity = element.SolidOpacity;
        StopColor = element.StopColor;
        StopOpacity = element.StopOpacity;
        Stroke = element.Stroke;
        StrokeDasharray = element.StrokeDasharray;
        StrokeDashoffset = element.StrokeDashoffset;
        StrokeLinecap = element.StrokeLinecap;
        StrokeLinejoin = element.StrokeLinejoin;
        StrokeMiterlimit = element.StrokeMiterlimit;
        StrokeOpacity = element.StrokeOpacity;
        StrokeWidth = element.StrokeWidth;
        TextAnchor = element.TextAnchor;
        TextDecoration = element.TextDecoration;
        TextRendering = element.TextRendering;
        Transform = element.Transform;
        UnicodeBidi = element.UnicodeBidi;
        VectorEffect = element.VectorEffect;
        Visibility = element.Visibility;
        WordSpacing = element.WordSpacing;
        WritingMode = element.WritingMode;

        _bind_getter_setter();
        return *this;
    }
    bool SVGIElement::operator==(const SVGElement &element) const {
        return SVGElement::operator==(element);
    }
    bool SVGIElement::operator!=(const SVGElement &element) const {
        return SVGElement::operator!=(element);
    }
    const std::string SVGIElement::operator-(const SVGElement &element) const {
        return SVGElement::operator-(element);
    }
}
