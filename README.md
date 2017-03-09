This is a collaboration project on reliable protocol over UDP for Linux systems.

**Planed features:**
- semi-reliability(with given timeout)
- reliability(packets will get to the target until connection is lost)
- ordering
- congestion avoidance

**Planed show-off:**  
Synchronization of big amount of physical objects.

###Current usage
Currently you can make two sockets talk to eachother.  
Compile project.  
call `./RUDP --port 8062` to start listening at port 8062 in first terminal  
call `./RUDP --port 8063 --sendto 8062 --send` to start sending to 9062 on second terminal  
Type stuff in the second terminal. All words will be sent as separate packages and printed in first terminal. 
