const obj="<countries>"+
    "<country>"+
        "<name>India</name>"+
        "<score>100</score>"+
        "<wicket>10</wicket>"+
        "<over>50</over>"+
    "</country>"+
    "<country>"+
        "<name>Australia</name>"+
        "<score>200</score>"+
        "<wicket>10</wicket>"+
        "<over>50</over>"+
    "</country>"+
    "</countries>";
let parse=new DOMParser()
let xmlDoc=parse.parseFromString(obj,"text/xml");
document.write(xmlDoc.getElementsByTagName("score")[0].childNodes[0].nodeValue+"<hr>")
document.write(xmlDoc.getElementsByTagName("score")[1].childNodes[0].nodeValue)

    
