Tiene que lograr extraer del programa la parte en donde se extraer la configuración del puerto serial: 
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
La configuracion para arduino esta en este video: 
https://www.youtube.com/watch?v=UD78xyKbrfk
Para tomar los datos normalmente se usa: 
http://qt-project.org/forums/viewthread/21698

 

