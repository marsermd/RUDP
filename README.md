This is a collaboration project on reliable protocol over UDP for Linux systems.

**Dependencies**
- install protobuf to be able to compile this project

**features:**
- reliability layer over UDP

**Planed show-off:**  
_Probably won't happen_
Synchronization of big amount of physical objects.

**Current usage**
If you compile the project, you two reliable sockets will be created and connected over UDP at ports 8092 and 8094.   

Each 10 ms a message will be sent from one socket to another and printed in console output. You can simulate package loss and latency using external tools like [tc](https://stackoverflow.com/questions/614795/simulate-delayed-and-dropped-packets-on-linux).
