/* 
 * File:   BufferPoolADT.h
 * Author: Clifford A. Shaffer, Dept of CompSci, Virginia Tech
 *         Page 286 of Data Structures and Algorithm Analysis
 *         Edition 3.2 (C++ Version)
 *
 * Created on June 5, 2012
 */

#ifndef BUFFERPOOLADT_H
#define	BUFFERPOOLADT_H

// ADT for buffer pools using the message-passing style
class BufferPool {
public:
    //Constructors/Destructors
    BufferPool() {}
    virtual ~BufferPool() {}
    
    // Copy "sz" bytes from "space" to position "pos" in the
    //   buffered storage.
    virtual void insert(char* space, int sz, int pos) = 0;
    
    // Copy "sz" bytes from position "pos" of the buffered
    //   storage to "space".
    virtual void getbytes(char* space, int sz, int pos) = 0;
};


#endif	/* BUFFERPOOLADT_H */

