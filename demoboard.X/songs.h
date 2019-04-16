#include "notes.h"

#ifdef DEMOSONG

#define CHANNELS 4

__prog__ const unsigned short c1f[] __attribute__((space(prog))) = {
    C4, C4, C4, C4, C4, C4, C4, C4, C4, C4,
    B3, B3, B3, B3, B3, B3, B3, B3, B3, B3, B3, B3,
};

__prog__ const unsigned short c1a[] __attribute__((space(prog))) = {
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
};

__prog__ const unsigned short c2f[] __attribute__((space(prog))) = {
   Eb3,Eb3,Eb3,Eb3,Eb3,Eb3,Eb3,Eb3, F3, F3,
    D3, D3, D3, D3, D3, D3, D3, D3, D3, D3, D3, D3,
};

__prog__ const unsigned short c2a[] __attribute__((space(prog))) = {
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
};

__prog__ const unsigned short c3f[] __attribute__((space(prog))) = {
    G3, G3, G3, G3, G3, G3, G3, G3,Ab3,Ab3,
    G3, G3, G3, G3, G3, G3, G3, G3, G3, G3, G3, G3,
};

__prog__ const unsigned short c3a[] __attribute__((space(prog))) = {
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
};

__prog__ const unsigned short c4f[] __attribute__((space(prog))) = {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short c4a[] __attribute__((space(prog))) = {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short fltr[] __attribute__((space(prog))) = {
     0,  0, 21,  0,  0, 21,  0, 21,  0, 21,
     0,  0, 21,  0,  0, 21,  0,  0, 21,  0,  0, 21,
};

#endif //DEMOSONG

#ifdef STILL_ALIVE

#define CHANNELS 4

__prog__ const unsigned short c1f[] __attribute__((space(prog))) = {
                     G5,Gb5, E5, E5,// this was a tri
    Gb5,  0,  0,  0,  0,  0,  0,  0,// umph
      0,  0,  0, A4, G5,Gb5, E5, E5,// I'm making a note
     E5,Gb5,  0,  0, D5, D5, E5, A4,// here  huge suc
     A4,  0,  0,  0,  0,  0,  0, A4,// cess it's
     E5, E5,Gb5, G5, G5, G5, E5,Db5,// hard to over state
    Db5, D5, D5, D5, E5, E5, A4, A4,// my satis
     A4,Gb5,Gb5,  0,  0,  0,  0,  0,// faction
      0,  0,  0,  0, G5,Gb5, E5, E5,// aperture scien
    Gb5,  0,  0,  0,  0,  0,  0,  0,// ce
      0,  0,  0, A4, G5,Gb5, E5, E5,// we do what we must
      0,  0,Gb5, D5,  0,  0, E5, A4,// because we can
     A4,  0,  0,  0,  0,  0,  0,  0,
     E5, E5,Gb5, G5, G5, G5, E5,Db5,// For the good of all
    Db5,Db5, D5, E5,  0, A4, D5, E5,// of us except the
     F5, E5, D5, C5,  0,  0, A4,Bb4,// ones who are dead but theres
     C5, C5, F5, F5, E5, D5, D5, C5,// no sense crying over
     D5, C5, C5, C5, C5, C5, A4,Bb4,// every mistake you just
     C5, C5, F5, F5, G5, F5, E5, D5,// keep on trying till you
     D5, E5, F5, F5, F5, F5, G5, A5,// run out of cake and the
    Bb5,Bb5, A5, A5, G5, G5, F5, G5,// science gets done and you
     A5, A5, G5, G5, F5, F5, D5, C5,// make a neat gun for the
     D5, F5, F5, E5, E5, E5,Gb5,Gb5,// people who are still alive
    Gb5,Gb5,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0, A4, G5,Gb5, E5, E5,// I'm not even an
     E5,Gb5,  0,  0,  0,  0,  0,  0,// gry
      0,  0,  0,  0, G5,Gb5, E5, E5,// I'm being so
     E5, E5,Gb5, D5, D5, E5, E5, A4,//sincere right now
     A4,  0,  0,  0,  0,  0,  0,  0,
     E5, E5,Gb5, G5, G5, G5, E5, E5,// even though you
    Db5,Db5, D5, E5, E5, E5, A4, A4,// broke my heard and killed
     A4,Gb5,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0, A4, G5,Gb5, E5, E5,// and tore me to piec
    Gb5,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0, A4, G5,Gb5, E5, E5,// and threw every piece
      0,  0,Gb5, D5,  0,  0, E5, A4,// into a fire
     A4,  0,  0,  0,  0,  0,  0,  0,
     E5, E5,Gb5, G5, G5, G5, E5, E5,// as they burned it
    Db5,Db5, D5, E5,  0, A4, D5, E5,// hurt because I was so
     F5, E5, D5, C5,  0,  0, A4,Bb4,// happy for you! now these
     C5, C5, F5, F5, E5, D5, D5, C5,// points of data make a
     D5, C5, C5, C5, C5, C5, A4,Bb4,// beautiful line and we're
     C5, C5, F5, F5, G5, F5, E5, D5,// out of beta we're re
     D5, E5, F5, F5, F5, F5, G5, A5,// leasing on time So I'm
    Bb5,Bb5, A5, A5, G5, G5, F5, G5,// glad I got burned think of
     A5, A5, G5, F5, F5, F5, D5, C5,// all the things we learned for the
     D5, F5, F5, E5, E5, E5,Gb5,Gb5,// people whe are still alive
    Gb5,Gb5,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0, G5,Gb5, E5, E5,// go head and leave
     E5,Gb5,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0, A4, G5,Gb5, E5, E5,// I think I prefer
      0,  0,Gb5, D5,  0,  0, E5, A4,// to stay inside
     A4,  0,  0,  0,  0,  0,  0,  0,
     E5, E5,Gb5, G5, G5, G5, E5, E5,// maybe you'll find
    Db5,Db5, D5, E5, E5, E5, A4, A4,// someone else to help
     A4,Gb5,Gb5,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0, G5,Gb5, E5, E5,// maybe black me
     E5,Gb5,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0, G5,Gb5, E5, E5,// that was a joke
      0,  0,Gb5, D5,  0,  0, E5, A4,// HAHA FAT CHANCE
     A4,  0,  0,  0,  0,  0,  0,  0,
     E5, E5,Gb5, G5, G5, G5, E5, E5,// any way this
    Db5,Db5, D5, E5,  0, A4, D5, E5,// cake is great it's so de
     F5, E5, D5, C5,  0,  0, A4,Bb4,// licious and moist look at
     C5, C5, F5, F5, E5, D5, D5, C5,// me still talking when there's
     D5, C5, C5, C5, C5, C5, A4,Bb4,// science to do when i
     C5, C5, F5, F5, G5, F5, E5, D5,// look out there it makes me
     D5, E5, F5, F5, F5, F5, G5, A5,// glad I'm not you I've ex
    Bb5,Bb5, A5, A5, G5, G5, F5, G5,// periments to run there is
     A5, A5, G5, F5, F5, F5, D5, C5,// research to be done on the
     D5, F5, F5, E5, E5, E5,Gb5,Gb5,// people whe are still alive
    Gb5,Gb5,  0,  0,  0,  0, A5, A5,// and be
    Bb5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// lieve me I am still alive
    Gb5,Gb5,  0,  0,  0, A5, A5, A5,// I'm doing
     B5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// science and I'm still alive
    Gb5,Gb5,  0,  0,  0, A5, A5, A5,// I feel fan
     B5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// tastic and I'm still alive
    Gb5,Gb5,  0,  0,  0,  0, A5, A5,// while you're
     B5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// dying I'll be still alive
    Gb5,Gb5,  0,  0,  0, A5, A5, A5,// and when you're
     B5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// dead I'll be still alive
    Gb5,Gb5,  0,  0,  0, G5, A5, A5,// still alive
     A5, A5,  0,  0,  0, G5,Gb5,Gb5,// still alive
     Gb5,Gb5, 0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short c1a[] __attribute__((space(prog))) = {
                     20, 20, 20, 20,// this was a tri
     20,  0,  0,  0,  0,  0,  0,  0,// umph
      0,  0,  0, 20, 20, 20, 20, 20,// I'm making a note
     20, 20,  0,  0, 20, 20, 20, 20,// here  huge suc
     20,  0,  0,  0,  0,  0,  0, 20,// cess it's
     20, 20, 20, 20, 20, 20, 20, 20,// hard to over state
     20, 20, 20, 20, 20, 20, 20, 20,// my satis
     20, 20, 20,  0,  0,  0,  0,  0,// faction
      0,  0,  0,  0, 20, 20, 20, 20,// aperture scien
     20,  0,  0,  0,  0,  0,  0,  0,// ce
      0,  0,  0, 20, 20, 20, 20, 20,// we do what we must
      0,  0, 20, 20,  0,  0, 20, 20,// because we can
     20,  0,  0,  0,  0,  0,  0,  0,
     20, 20, 20, 20, 20, 20, 20, 20,// For the good of all
     20, 20, 20, 20,  0, 20, 20, 20,// of us except the
     20, 20, 20, 20,  0,  0, 20, 20,// ones who are dead but theres
     20, 20, 20, 20, 20, 20, 20, 20,// no sense crying over
     20, 20, 20, 20, 20, 20, 20, 20,// every mistake you just
     20, 20, 20, 20, 20, 20, 20, 20,// keep on trying till you
     20, 20, 20, 20, 20, 20, 20, 20,// run out of cake and the
     20, 20, 20, 20, 20, 20, 20, 20,// science gets done and you
     20, 20, 20, 20, 20, 20, 20, 20,// make a neat gun for the
     20, 20, 20, 20, 20, 20, 20, 20,// people who are still alive
     20, 20,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0, 20, 20, 20, 20, 20,// I'm not even an
     20, 20,  0,  0,  0,  0,  0,  0,// gry
      0,  0,  0,  0, 20, 20, 20, 20,// I'm being so
     20, 20, 20, 20, 20, 20, 20, 20,//sincere right now
     20,  0,  0,  0,  0,  0,  0,  0,
     20, 20, 20, 20, 20, 20, 20, 20,// even though you
     20, 20, 20, 20, 20, 20, 20, 20,// broke my heard and killed
     20, 20,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0, 20, 20, 20, 20, 20,// and tore me to piec
     20,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0, 20, 20, 20, 20, 20,// and threw every piece
      0,  0, 20, 20,  0,  0, 20, 20,// into a fire
     20,  0,  0,  0,  0,  0,  0,  0,
     20, 20, 20, 20, 20, 20, 20, 20,// as they burned it
     20, 20, 20, 20,  0, 20, 20, 20,// hurt because I was so
     20, 20, 20, 20,  0,  0, 20, 20,// happy for you! now these
     20, 20, 20, 20, 20, 20, 20, 20,// points of data make a
     20, 20, 20, 20, 20, 20, 20, 20,// beautiful line and we're
     20, 20, 20, 20, 20, 20, 20, 20,// out of beta we're re
     20, 20, 20, 20, 20, 20, 20, 20,// leasing on time So I'm
     20, 20, 20, 20, 20, 20, 20, 20,// glad I got burned think of
     20, 20, 20, 20, 20, 20, 20, 20,// all the things we learned for the
     20, 20, 20, 20, 20, 20, 20, 20,// people whe are still alive
     20, 20,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0, 20, 20, 20, 20,// go head and leave
     20, 20,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0, 20, 20, 20, 20, 20,// I think I prefer
      0,  0, 20, 20,  0,  0, 20, 20,// to stay inside
     20,  0,  0,  0,  0,  0,  0,  0,
     20, 20, 20, 20, 20, 20, 20, 20,// maybe you'll find
     20, 20, 20, 20, 20, 20, 20, 20,// someone else to help
     20, 20,  0,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0, 20, 20, 20, 20,// maybe black me
     20, 20,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0, 20, 20, 20, 20,// that was a joke
      0,  0, 20, 20,  0,  0, 20, 20,// HAHA FAT CHANCE
     20,  0,  0,  0,  0,  0,  0,  0,
     20, 20, 20, 20, 20, 20, 20, 20,// any way this
     20, 20, 20, 20,  0, 20, 20, 20,// cake is great it's so de
     20, 20, 20, 20,  0,  0, 20, 20,// licious and moist look at
     20, 20, 20, 20, 20, 20, 20, 20,// me still talking when there's
     20, 20, 20, 20, 20, 20, 20, 20,// science to do when i
     20, 20, 20, 20, 20, 20, 20, 20,// look out there it makes me
     20, 20, 20, 20, 20, 20, 20, 20,// glad I'm not you I've ex
     20, 20, 20, 20, 20, 20, 20, 20,// periments to run there is
     20, 20, 20, 20, 20, 20, 20, 20,// research to be done on the
     20, 20, 20, 20, 20, 20, 20, 20,// people whe are still alive
     20, 20,  0,  0,  0,  0, 20, 20,// and be
     20, 20, 20, 20, 20, 20, 20, 20,// lieve me I am still alive
     20, 20,  0,  0,  0, 20, 20, 20,// I'm doing
     20, 20, 20, 20, 20, 20, 20, 20,// science and I'm still alive
     20, 20,  0,  0,  0, 20, 20, 20,// I feel fan
     20, 20, 20, 20, 20, 20, 20, 20,// tastic and I'm still alive
     20, 20,  0,  0,  0,  0, 20, 20,// while you're
     20, 20, 20, 20, 20, 20, 20, 20,// dying I'll be still alive
     20, 20,  0,  0,  0, 20, 20, 20,// and when you're
     20, 20, 20, 20, 20, 20, 20, 20,// dead I'll be still alive
     20, 20,  0,  0,  0, 20, 20, 20,// still alive
     20, 20,  0,  0,  0, 20, 20, 20,// still alive
     20, 20,  0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short fltr[] __attribute__((space(prog))) = {
                      3,  3,  3,  2,// this was a tri
      3,  0,  0,  0,  0,  0,  0,  0,// umph
      0,  0,  0,  0,  0,  0,  0,  0,// I'm making a note
      0,  0,  0,  0,  0,  0,  0,  0,// here  huge suc
      0,  0,  0,  0,  0,  0,  0,  0,// cess it's
      0,  0,  0,  0,  0,  0,  0,  0,// hard to over state
      0,  0,  0,  0,  0,  0,  0,  0,// my satis
      0,  0,  0,  0,  0,  0,  0,  0,// faction
      0,  0,  0,  0,  0,  0,  0,  0,// aperture scien
      0,  0,  0,  0,  0,  0,  0,  0,// ce
      0,  0,  0,  0,  0,  0,  0,  0,// we do what we must
      0,  0,  0,  0,  0,  0,  0,  0,// because we can
      0,  0,  0,  0,  0,  0,  0,  0,// 
      0,  0,  0,  0,  0,  0,  0,  0,// For the good of all
      0,  0,  0,  0,  0,  0,  0,  0,// of us except the
      0,  0,  0,  0,  0,  0,  0,  0,// ones who are dead but theres
      4,  5,  4,  0,  5,  5,  5,  0,// no sense crying over
      0,  5,  4,  5,  0,  5,  5,  5,// every mistake you just
      0,  0,  0,  0,  0,  0,  0,  0,// keep on trying till you
      0,  0,  0,  0,  0,  0,  0,  0,// run out of cake and the
      0,  0,  0,  0,  0,  0,  0,  0,// science gets done and you
      0,  0,  0,  0,  0,  0,  0,  0,// make a neat gun for the
      0,  0,  0,  0,  0,  0,  0,  0,// people who are still alive
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// I'm not even an
      0,  0,  0,  0,  0,  0,  0,  0,// gry
      0,  0,  0,  0,  0,  0,  0,  0,// I'm being so
      0,  0,  0,  0,  0,  0,  0,  0,//sincere right now
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// even though you
      0,  0,  0,  0,  0,  0,  0,  0,// broke my heard and killed
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// and tore me to piec
      0,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0,  0,  0,  0,  0,  0,// and threw every piece
      0,  0,  0,  0,  0,  0,  0,  0,// into a fire
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// as they burned it
      0,  0,  0,  0,  0,  0,  0,  0,// hurt because I was so
      0,  0,  0,  0,  0,  0,  0,  0,// happy for you! now these
      0,  0,  0,  0,  0,  0,  0,  0,// points of data make a
      0,  0,  0,  0,  0,  0,  0,  0,// beautiful line and we're
      0,  0,  0,  0,  0,  0,  0,  0,// out of beta we're re
      0,  0,  0,  0,  0,  0,  0,  0,// leasing on time So I'm
      0,  0,  0,  0,  0,  0,  0,  0,// glad I got burned think of
      0,  0,  0,  0,  0,  0,  0,  0,// all the things we learned for the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// go head and leave
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// I think I prefer
      0,  0,  0,  0,  0,  0,  0,  0,// to stay inside
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// maybe you'll find
      0,  0,  0,  0,  0,  0,  0,  0,// someone else to help
      0,  0,  0,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0,  0,  0,  0,  0,// maybe black me
      0,  0,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0,  0,  0,  0,  0,// that was a joke
      0,  0,  0,  0,  0,  0,  0,  0,// HAHA FAT CHANCE
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// any way this
      0,  0,  0,  0,  0,  0,  0,  0,// cake is great it's so de
      0,  0,  0,  0,  0,  0,  0,  0,// licious and moist look at
      0,  0,  0,  0,  0,  0,  0,  0,// me still talking when there's
      0,  0,  0,  0,  0,  0,  0,  0,// science to do when i
      0,  0,  0,  0,  0,  0,  0,  0,// look out there it makes me
      0,  0,  0,  0,  0,  0,  0,  0,// glad I'm not you I've ex
      0,  0,  0,  0,  0,  0,  0,  0,// periments to run there is
      0,  0,  0,  0,  0,  0,  0,  0,// research to be done on the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and be
      0,  0,  0,  0,  0,  0,  0,  0,// lieve me I am still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I'm doing
      0,  0,  0,  0,  0,  0,  0,  0,// science and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I feel fan
      0,  0,  0,  0,  0,  0,  0,  0,// tastic and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// while you're
      0,  0,  0,  0,  0,  0,  0,  0,// dying I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and when you're
      0,  0,  0,  0,  0,  0,  0,  0,// dead I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short c2f[] __attribute__((space(prog))) = {
                      0,  0,  0,  0,// this was a tri
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// umph
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// I'm making a note
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// here  huge suc
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// cess it's
     A3, E4, G4, E4, A3, E4, G4, E4,// hard to over state
     A3,Db4, G4,Db4, A3,Db4, G4,Db4,// my satis
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// faction
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// aperture scien
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// ce
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// we do what we must
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,// because we can
     A3, D4,Gb4, D4, B3, D4,Gb4, D4,
     A3, E4, G4, E4, A3, E4, G4, E4,// For the good of all
     A3,Db4, G4,Db4, A3,Db4, G4,Db4,// of us except the
    Bb3, D4, F4, A4, A4, A4,  0,  0,// ones who are dead but theres
     F4, A4, F4,  0, E4, G4, E4,  0,// no sense crying over
     D4, D4, D4, E4, F4, F4, F4, F4,// every mistake you just
     F4, A4, F4,  0, E4, G4, E4,  0,// keep on trying till you
     D4, D4, D4, E4, F4, F4, F4, F4,// run out of cake and the
     D4, G4, D4, G4, E4, G4, E4, G4,// science gets done and you
     F4, A4, F4, A4, F4, A4, F4, A4,// make a neat gun for the
     D4, G4, D4, G4,Db4, G4,Db4, G4,// people who are still alive
      0, D4,Gb4, D4,  0, A4,Gb4, D4,
      0, D4,Gb4, D4,  0, A4,Gb4, D4,
      0, D4,Gb4, D4,  0, A4,Gb4, D4,
      0, D4,Gb4, D4,  0, A4,Gb4, D4,// I'm not even an
      0, D4,Gb4, D4,  0, A4,Gb4, D4,// gry
      0, D4,Gb4, D4,  0, A4,Gb4, D4,// I'm being so
      0, D4,Gb4, D4,  0, A4,Gb4, D4,//sincere right now
      0, D4,Gb4, D4,  0, A4,Gb4, D4,
     E5, E5,Gb5, G5, G5, G5, E5, E5,// even though you
    Db5,Db5, D5, E5, E5, E5, A4, A4,// broke my heard and killed
     A4,Gb5,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0, A4, G5,Gb5, E5, E5,// and tore me to piec
    Gb5,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0, A4, G5,Gb5, E5, E5,// and threw every piece
      0,  0,Gb5, D5,  0,  0, E5, A4,// into a fire
     A4,  0,  0,  0,  0,  0,  0,  0,
     E5, E5,Gb5, G5, G5, G5, E5, E5,// as they burned it
    Db5,Db5, D5, E5,  0, A4, D5, E5,// hurt because I was so
     F5, E5, D5, C5,  0,  0, A4,Bb4,// happy for you! now these
     C5, C5, F5, F5, E5, D5, D5, C5,// points of data make a
     D5, C5, C5, C5, C5, C5, A4,Bb4,// beautiful line and we're
     C5, C5, F5, F5, G5, F5, E5, D5,// out of beta we're re
     D5, E5, F5, F5, F5, F5, G5, A5,// leasing on time So I'm
    Bb5,Bb5, A5, A5, G5, G5, F5, G5,// glad I got burned think of
     A5, A5, G5, F5, F5, F5, D5, C5,// all the things we learned for the
     D5, F5, F5, E5, E5, E5,Gb5,Gb5,// people whe are still alive
    Gb5,Gb5,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0, G5,Gb5, E5, E5,// go head and leave
     E5,Gb5,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0, A4, G5,Gb5, E5, E5,// I think I prefer
      0,  0,Gb5, D5,  0,  0, E5, A4,// to stay inside
     A4,  0,  0,  0,  0,  0,  0,  0,
     E5, E5,Gb5, G5, G5, G5, E5, E5,// maybe you'll find
    Db5,Db5, D5, E5, E5, E5, A4, A4,// someone else to help
     A4,Gb5,Gb5,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0, G5,Gb5, E5, E5,// maybe black me
     E5,Gb5,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0, G5,Gb5, E5, E5,// that was a joke
      0,  0,Gb5, D5,  0,  0, E5, A4,// HAHA FAT CHANCE
     A4,  0,  0,  0,  0,  0,  0,  0,
     E5, E5,Gb5, G5, G5, G5, E5, E5,// any way this
    Db5,Db5, D5, E5,  0, A4, D5, E5,// cake is great it's so de
     F5, E5, D5, C5,  0,  0, A4,Bb4,// licious and moist look at
     C5, C5, F5, F5, E5, D5, D5, C5,// me still talking when there's
     D5, C5, C5, C5, C5, C5, A4,Bb4,// science to do when i
     C5, C5, F5, F5, G5, F5, E5, D5,// look out there it makes me
     D5, E5, F5, F5, F5, F5, G5, A5,// glad I'm not you I've ex
    Bb5,Bb5, A5, A5, G5, G5, F5, G5,// periments to run there is
     A5, A5, G5, F5, F5, F5, D5, C4,// research to be done on the
     D5, F5, F5, E5, E5, E5,Gb5,Gb5,// people whe are still alive
    Gb5,Gb5,  0,  0,  0,  0, A5, A5,// and be
    Bb5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// lieve me I am still alive
    Gb5,Gb5,  0,  0,  0, A5, A5, A5,// I'm doing
     B5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// science and I'm still alive
    Gb5,Gb5,  0,  0,  0, A5, A5, A5,// I feel fan
     B5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// tastic and I'm still alive
    Gb5,Gb5,  0,  0,  0,  0, A5, A5,// while you're
     B5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// dying I'll be still alive
    Gb5,Gb5,  0,  0,  0, A5, A5, A5,// and when you're
     B5, A5,Gb5, D5, D5, E5,Gb5,Gb5,// dead I'll be still alive
    Gb5,Gb5,  0,  0,  0, G5, A5, A5,// still alive
     A5, A5,  0,  0,  0, G5,Gb5,Gb5,// still alive
     Gb5,Gb5, 0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short c2a[] __attribute__((space(prog))) = {
                      0,  0,  0,  0,// this was a tri
     12, 12, 12, 12, 12, 12, 12, 12,// umph
     12, 12, 12, 12, 12, 12, 12, 12,// I'm making a note
     12, 12, 12, 12, 12, 12, 12, 12,// here  huge suc
     12, 12, 12, 12, 12, 12, 12, 12,// cess it's
     12, 12, 12, 12, 12, 12, 12, 12,// hard to over state
     12, 12, 12, 12, 12, 12, 12, 12,// my satis
     12, 12, 12, 12, 12, 12, 12, 12,// faction
     12, 12, 12, 12, 12, 12, 12, 12,// aperture scien
     12, 12, 12, 12, 12, 12, 12, 12,// ce
     12, 12, 12, 12, 12, 12, 12, 12,// we do what we must
     12, 12, 12, 12, 12, 12, 12, 12,// because we can
     12, 12, 12, 12, 12, 12, 12, 12,
     12, 12, 12, 12, 12, 12, 12, 12,// For the good of all
     12, 12, 12, 12, 12, 12, 12, 12,// of us except the
     12, 12, 12, 12, 12, 10,  0,  0,// ones who are dead but theres
     10, 10, 10,  0, 10, 10, 10,  0,// no sense crying over
     10, 10, 10, 10, 10, 10, 10,  0,// every mistake you just
     10, 10, 10,  0, 10, 10, 10,  0,// keep on trying till you
     10, 10, 10, 10, 10, 10, 10,  0,// run out of cake and the
     10, 10, 10, 10, 10, 10, 10, 10,// science gets done and you
     10, 10, 10, 10, 10, 10, 10, 10,// make a neat gun for the
     10, 10, 10, 10, 10, 10, 10, 10,// people who are still alive
      0, 10, 12, 12,  0, 12, 12, 12,
      0, 10, 12, 12,  0, 12, 12, 12,
      0, 10, 12, 12,  0, 12, 12, 12,
      0, 10, 12, 12,  0, 12, 12, 12,// I'm not even an
      0, 10, 12, 12,  0, 12, 12, 12,// gry
      0, 10, 12, 12,  0, 12, 12, 12,// I'm being so
      0, 10, 12, 12,  0, 12, 12, 12,//sincere right now
      0, 10, 12, 12,  0, 12, 12, 12,
      0,  0,  0,  0,  0,  0,  0,  0,// even though you
      0,  0,  0,  0,  0,  0,  0,  0,// broke my heard and killed
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// and tore me to piec
      0,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0,  0,  0,  0,  0,  0,// and threw every piece
      0,  0,  0,  0,  0,  0,  0,  0,// into a fire
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// as they burned it
      0,  0,  0,  0,  0,  0,  0,  0,// hurt because I was so
      0,  0,  0,  0,  0,  0,  0,  0,// happy for you! now these
      0,  0,  0,  0,  0,  0,  0,  0,// points of data make a
      0,  0,  0,  0,  0,  0,  0,  0,// beautiful line and we're
      0,  0,  0,  0,  0,  0,  0,  0,// out of beta we're re
      0,  0,  0,  0,  0,  0,  0,  0,// leasing on time So I'm
      0,  0,  0,  0,  0,  0,  0,  0,// glad I got burned think of
      0,  0,  0,  0,  0,  0,  0,  0,// all the things we learned for the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// go head and leave
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// I think I prefer
      0,  0,  0,  0,  0,  0,  0,  0,// to stay inside
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// maybe you'll find
      0,  0,  0,  0,  0,  0,  0,  0,// someone else to help
      0,  0,  0,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0,  0,  0,  0,  0,// maybe black me
      0,  0,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0,  0,  0,  0,  0,// that was a joke
      0,  0,  0,  0,  0,  0,  0,  0,// HAHA FAT CHANCE
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// any way this
      0,  0,  0,  0,  0,  0,  0,  0,// cake is great it's so de
      0,  0,  0,  0,  0,  0,  0,  0,// licious and moist look at
      0,  0,  0,  0,  0,  0,  0,  0,// me still talking when there's
      0,  0,  0,  0,  0,  0,  0,  0,// science to do when i
      0,  0,  0,  0,  0,  0,  0,  0,// look out there it makes me
      0,  0,  0,  0,  0,  0,  0,  0,// glad I'm not you I've ex
      0,  0,  0,  0,  0,  0,  0,  0,// periments to run there is
      0,  0,  0,  0,  0,  0,  0,  0,// research to be done on the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and be
      0,  0,  0,  0,  0,  0,  0,  0,// lieve me I am still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I'm doing
      0,  0,  0,  0,  0,  0,  0,  0,// science and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I feel fan
      0,  0,  0,  0,  0,  0,  0,  0,// tastic and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// while you're
      0,  0,  0,  0,  0,  0,  0,  0,// dying I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and when you're
      0,  0,  0,  0,  0,  0,  0,  0,// dead I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short c3f[] __attribute__((space(prog))) = {
                      0,  0,  0,  0,// this was a tri
      0,  0,  0,  0,  0,  0,  0,  0,// umph
      0,  0,  0,  0,  0,  0,  0,  0,// I'm making a note
      0,  0,  0,  0,  0,  0,  0,  0,// here  huge suc
      0,  0,  0,  0,  0,  0,  0,  0,// cess it's
      0,  0,  0,  0,  0,  0,  0,  0,// hard to over state
      0,  0,  0,  0,  0,  0,  0,  0,// my satis
      0,  0,  0,  0,  0,  0,  0,  0,// faction
      0,  0,  0,  0,  0,  0,  0,  0,// aperture scien
      0,  0,  0,  0,  0,  0,  0,  0,// ce
      0,  0,  0,  0,  0,  0,  0,  0,// we do what we must
      0,  0,  0,  0,  0,  0,  0,  0,// because we can
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// For the good of all
      0,  0,  0,  0,  0,  0,  0,  0,// of us except the
      0,  0,  0,  0,  0,  0,  0,  0,// ones who are dead but theres
     C4, C4, C4, C4, C4, C4, C4, C4,// no sense crying over
    Bb3,  0,Bb3,  0, C4,  0, C4,  0,// every mistake you just
     C4,  0, C4,  0, C4,  0, C4,  0,// keep on trying till you
    Bb3,  0,Bb3,  0, C4,  0, C4,  0,// run out of cake and the
    Bb3,  0,Bb3,  0, C4,  0, C4,  0,// science gets done and you
     C4,  0, C4,  0, D4,  0, D4,  0,// make a neat gun for the
    Bb3,  0,Bb3,  0, A3,  0, A3,  0,// people who are still alive
      0,  0, A3, A3, A3,  0,  0,  0,
      0,  0, A3, A3, A3,  0,  0,  0,
      0,  0, A3, A3, A3,  0,  0,  0,
      0,  0, A3, A3, A3,  0,  0,  0,// I'm not even an
      0,  0, A3, A3, A3,  0,  0,  0,// gry
      0,  0, A3, A3, A3,  0,  0,  0,// I'm being so
      0,  0, A3, A3, A3,  0,  0,  0,//sincere right now
      0,  0, A3, A3, A3,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// even though you
      0,  0,  0,  0,  0,  0,  0,  0,// broke my heard and killed
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// and tore me to piec
      0,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0,  0,  0,  0,  0,  0,// and threw every piece
      0,  0,  0,  0,  0,  0,  0,  0,// into a fire
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// as they burned it
      0,  0,  0,  0,  0,  0,  0,  0,// hurt because I was so
      0,  0,  0,  0,  0,  0,  0,  0,// happy for you! now these
      0,  0,  0,  0,  0,  0,  0,  0,// points of data make a
      0,  0,  0,  0,  0,  0,  0,  0,// beautiful line and we're
      0,  0,  0,  0,  0,  0,  0,  0,// out of beta we're re
      0,  0,  0,  0,  0,  0,  0,  0,// leasing on time So I'm
      0,  0,  0,  0,  0,  0,  0,  0,// glad I got burned think of
      0,  0,  0,  0,  0,  0,  0,  0,// all the things we learned for the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// go head and leave
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// I think I prefer
      0,  0,  0,  0,  0,  0,  0,  0,// to stay inside
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// maybe you'll find
      0,  0,  0,  0,  0,  0,  0,  0,// someone else to help
      0,  0,  0,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0,  0,  0,  0,  0,// maybe black me
      0,  0,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0,  0,  0,  0,  0,// that was a joke
      0,  0,  0,  0,  0,  0,  0,  0,// HAHA FAT CHANCE
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// any way this
      0,  0,  0,  0,  0,  0,  0,  0,// cake is great it's so de
      0,  0,  0,  0,  0,  0,  0,  0,// licious and moist look at
      0,  0,  0,  0,  0,  0,  0,  0,// me still talking when there's
      0,  0,  0,  0,  0,  0,  0,  0,// science to do when i
      0,  0,  0,  0,  0,  0,  0,  0,// look out there it makes me
      0,  0,  0,  0,  0,  0,  0,  0,// glad I'm not you I've ex
      0,  0,  0,  0,  0,  0,  0,  0,// periments to run there is
      0,  0,  0,  0,  0,  0,  0,  0,// research to be done on the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and be
      0,  0,  0,  0,  0,  0,  0,  0,// lieve me I am still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I'm doing
      0,  0,  0,  0,  0,  0,  0,  0,// science and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I feel fan
      0,  0,  0,  0,  0,  0,  0,  0,// tastic and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// while you're
      0,  0,  0,  0,  0,  0,  0,  0,// dying I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and when you're
      0,  0,  0,  0,  0,  0,  0,  0,// dead I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short c3a[] __attribute__((space(prog))) = {
                      0,  0,  0,  0,// this was a tri
      0,  0,  0,  0,  0,  0,  0,  0,// umph
      0,  0,  0,  0,  0,  0,  0,  0,// I'm making a note
      0,  0,  0,  0,  0,  0,  0,  0,// here  huge suc
      0,  0,  0,  0,  0,  0,  0,  0,// cess it's
      0,  0,  0,  0,  0,  0,  0,  0,// hard to over state
      0,  0,  0,  0,  0,  0,  0,  0,// my satis
      0,  0,  0,  0,  0,  0,  0,  0,// faction
      0,  0,  0,  0,  0,  0,  0,  0,// aperture scien
      0,  0,  0,  0,  0,  0,  0,  0,// ce
      0,  0,  0,  0,  0,  0,  0,  0,// we do what we must
      0,  0,  0,  0,  0,  0,  0,  0,// because we can
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// For the good of all
      0,  0,  0,  0,  0,  0,  0,  0,// of us except the
      0,  0,  0,  0,  0,  0,  0,  0,// ones who are dead but theres
     10,  3, 10,  3, 10,  3, 10,  3,// no sense crying over
     10,  3, 10,  3, 10,  3, 10,  3,// every mistake you just
     10,  3, 10,  3, 10,  3, 10,  3,// keep on trying till you
     10,  3, 10,  3, 10,  3, 10,  3,// run out of cake and the
     10,  3, 10,  3, 10,  3, 10,  3,// science gets done and you
     10,  3, 10,  3, 10,  3, 10,  3,// make a neat gun for the
     10,  3, 10,  3, 10,  3, 10,  3,// people who are still alive
      0,  0, 12, 12, 12,  0,  0,  0,
      0,  0, 12, 12, 12,  0,  0,  0,
      0,  0, 12, 12, 12,  0,  0,  0,
      0,  0, 12, 12, 12,  0,  0,  0,// I'm not even an
      0,  0, 12, 12, 12,  0,  0,  0,// gry
      0,  0, 12, 12, 12,  0,  0,  0,// I'm being so
      0,  0, 12, 12, 12,  0,  0,  0,//sincere right now
      0,  0, 12, 12, 12,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// even though you
      0,  0,  0,  0,  0,  0,  0,  0,// broke my heard and killed
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// and tore me to piec
      0,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0,  0,  0,  0,  0,  0,// and threw every piece
      0,  0,  0,  0,  0,  0,  0,  0,// into a fire
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// as they burned it
      0,  0,  0,  0,  0,  0,  0,  0,// hurt because I was so
      0,  0,  0,  0,  0,  0,  0,  0,// happy for you! now these
      0,  0,  0,  0,  0,  0,  0,  0,// points of data make a
      0,  0,  0,  0,  0,  0,  0,  0,// beautiful line and we're
      0,  0,  0,  0,  0,  0,  0,  0,// out of beta we're re
      0,  0,  0,  0,  0,  0,  0,  0,// leasing on time So I'm
      0,  0,  0,  0,  0,  0,  0,  0,// glad I got burned think of
      0,  0,  0,  0,  0,  0,  0,  0,// all the things we learned for the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// go head and leave
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// I think I prefer
      0,  0,  0,  0,  0,  0,  0,  0,// to stay inside
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// maybe you'll find
      0,  0,  0,  0,  0,  0,  0,  0,// someone else to help
      0,  0,  0,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0,  0,  0,  0,  0,// maybe black me
      0,  0,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0,  0,  0,  0,  0,// that was a joke
      0,  0,  0,  0,  0,  0,  0,  0,// HAHA FAT CHANCE
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// any way this
      0,  0,  0,  0,  0,  0,  0,  0,// cake is great it's so de
      0,  0,  0,  0,  0,  0,  0,  0,// licious and moist look at
      0,  0,  0,  0,  0,  0,  0,  0,// me still talking when there's
      0,  0,  0,  0,  0,  0,  0,  0,// science to do when i
      0,  0,  0,  0,  0,  0,  0,  0,// look out there it makes me
      0,  0,  0,  0,  0,  0,  0,  0,// glad I'm not you I've ex
      0,  0,  0,  0,  0,  0,  0,  0,// periments to run there is
      0,  0,  0,  0,  0,  0,  0,  0,// research to be done on the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and be
      0,  0,  0,  0,  0,  0,  0,  0,// lieve me I am still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I'm doing
      0,  0,  0,  0,  0,  0,  0,  0,// science and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I feel fan
      0,  0,  0,  0,  0,  0,  0,  0,// tastic and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// while you're
      0,  0,  0,  0,  0,  0,  0,  0,// dying I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and when you're
      0,  0,  0,  0,  0,  0,  0,  0,// dead I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short c4f[] __attribute__((space(prog))) = {
                      0,  0,  0,  0,// this was a tri
      0,  0,  0,  0,  0,  0,  0,  0,// umph
      0,  0,  0,  0,  0,  0,  0,  0,// I'm making a note
      0,  0,  0,  0,  0,  0,  0,  0,// here  huge suc
      0,  0,  0,  0,  0,  0,  0,  0,// cess it's
      0,  0,  0,  0,  0,  0,  0,  0,// hard to over state
      0,  0,  0,  0,  0,  0,  0,  0,// my satis
      0,  0,  0,  0,  0,  0,  0,  0,// faction
      0,  0,  0,  0,  0,  0,  0,  0,// aperture scien
      0,  0,  0,  0,  0,  0,  0,  0,// ce
      0,  0,  0,  0,  0,  0,  0,  0,// we do what we must
      0,  0,  0,  0,  0,  0,  0,  0,// because we can
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// For the good of all
      0,  0,  0,  0,  0,  0,  0,  0,// of us except the
      0,  0,  0,  0,  0,  0,  0,  0,// ones who are dead but theres
      0,  0,  0,  0,  0,  0,  0,  0,// no sense crying over
      0,  0,  0,  0,  0,  0,  0,  0,// every mistake you just
      0,  0,  0,  0,  0,  0,  0,  0,// keep on trying till you
      0,  0,  0,  0,  0,  0,  0,  0,// run out of cake and the
      0,  0,  0,  0,  0,  0,  0,  0,// science gets done and you
      0,  0,  0,  0,  0,  0,  0,  0,// make a neat gun for the
      0,  0,  0,  0,  0,  0,  0,  0,// people who are still alive
     D2, D2,  0, D2, B1, B1,  0, B1,
     D2, D2,  0, D2, B1, B1,  0, B1,
     D2, D2,  0, D2, B1, B1,  0, B1,
     D2, D2,  0, D2, B1, B1,  0, B1,// I'm not even an
     D2, D2,  0, D2, B1, B1,  0, B1,// gry
     D2, D2,  0, D2, B1, B1,  0, B1,// I'm being so
     D2, D2,  0, D2, B1, B1,  0, B1,//sincere right now
     D2, D2,  0, D2, B1, B1,  0, B1,
      0,  0,  0,  0,  0,  0,  0,  0,// even though you
      0,  0,  0,  0,  0,  0,  0,  0,// broke my heard and killed
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// and tore me to piec
      0,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0,  0,  0,  0,  0,  0,// and threw every piece
      0,  0,  0,  0,  0,  0,  0,  0,// into a fire
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// as they burned it
      0,  0,  0,  0,  0,  0,  0,  0,// hurt because I was so
      0,  0,  0,  0,  0,  0,  0,  0,// happy for you! now these
      0,  0,  0,  0,  0,  0,  0,  0,// points of data make a
      0,  0,  0,  0,  0,  0,  0,  0,// beautiful line and we're
      0,  0,  0,  0,  0,  0,  0,  0,// out of beta we're re
      0,  0,  0,  0,  0,  0,  0,  0,// leasing on time So I'm
      0,  0,  0,  0,  0,  0,  0,  0,// glad I got burned think of
      0,  0,  0,  0,  0,  0,  0,  0,// all the things we learned for the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// go head and leave
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// I think I prefer
      0,  0,  0,  0,  0,  0,  0,  0,// to stay inside
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// maybe you'll find
      0,  0,  0,  0,  0,  0,  0,  0,// someone else to help
      0,  0,  0,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0,  0,  0,  0,  0,// maybe black me
      0,  0,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0,  0,  0,  0,  0,// that was a joke
      0,  0,  0,  0,  0,  0,  0,  0,// HAHA FAT CHANCE
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// any way this
      0,  0,  0,  0,  0,  0,  0,  0,// cake is great it's so de
      0,  0,  0,  0,  0,  0,  0,  0,// licious and moist look at
      0,  0,  0,  0,  0,  0,  0,  0,// me still talking when there's
      0,  0,  0,  0,  0,  0,  0,  0,// science to do when i
      0,  0,  0,  0,  0,  0,  0,  0,// look out there it makes me
      0,  0,  0,  0,  0,  0,  0,  0,// glad I'm not you I've ex
      0,  0,  0,  0,  0,  0,  0,  0,// periments to run there is
      0,  0,  0,  0,  0,  0,  0,  0,// research to be done on the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and be
      0,  0,  0,  0,  0,  0,  0,  0,// lieve me I am still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I'm doing
      0,  0,  0,  0,  0,  0,  0,  0,// science and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I feel fan
      0,  0,  0,  0,  0,  0,  0,  0,// tastic and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// while you're
      0,  0,  0,  0,  0,  0,  0,  0,// dying I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and when you're
      0,  0,  0,  0,  0,  0,  0,  0,// dead I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,
};

__prog__ const unsigned short c4a[] __attribute__((space(prog))) = {
                      0,  0,  0,  0,// this was a tri
      0,  0,  0,  0,  0,  0,  0,  0,// umph
      0,  0,  0,  0,  0,  0,  0,  0,// I'm making a note
      0,  0,  0,  0,  0,  0,  0,  0,// here  huge suc
      0,  0,  0,  0,  0,  0,  0,  0,// cess it's
      0,  0,  0,  0,  0,  0,  0,  0,// hard to over state
      0,  0,  0,  0,  0,  0,  0,  0,// my satis
      0,  0,  0,  0,  0,  0,  0,  0,// faction
      0,  0,  0,  0,  0,  0,  0,  0,// aperture scien
      0,  0,  0,  0,  0,  0,  0,  0,// ce
      0,  0,  0,  0,  0,  0,  0,  0,// we do what we must
      0,  0,  0,  0,  0,  0,  0,  0,// because we can
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// For the good of all
      0,  0,  0,  0,  0,  0,  0,  0,// of us except the
      0,  0,  0,  0,  0,  0,  0,  0,// ones who are dead but theres
      0,  0,  0,  0,  0,  0,  0,  0,// no sense crying over
      0,  0,  0,  0,  0,  0,  0,  0,// every mistake you just
      0,  0,  0,  0,  0,  0,  0,  0,// keep on trying till you
      0,  0,  0,  0,  0,  0,  0,  0,// run out of cake and the
      0,  0,  0,  0,  0,  0,  0,  0,// science gets done and you
      0,  0,  0,  0,  0,  0,  0,  0,// make a neat gun for the
      0,  0,  0,  0,  0,  0,  0,  0,// people who are still alive
     15,  5,  0, 15, 15,  5,  0, 15,
     15,  5,  0, 15, 15,  5,  0, 15,
     15,  5,  0, 15, 15,  5,  0, 15,
     15,  5,  0, 15, 15,  5,  0, 15,// I'm not even an
     15,  5,  0, 15, 15,  5,  0, 15,// gry
     15,  5,  0, 15, 15,  5,  0, 15,// I'm being so
     15,  5,  0, 15, 15,  5,  0, 15,//sincere right now
     15,  5,  0, 15, 15,  5,  0, 15,
      0,  0,  0,  0,  0,  0,  0,  0,// even though you
      0,  0,  0,  0,  0,  0,  0,  0,// broke my heard and killed
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// and tore me to piec
      0,  0,  0,  0,  0,  0,  0,  0,// es
      0,  0,  0,  0,  0,  0,  0,  0,// and threw every piece
      0,  0,  0,  0,  0,  0,  0,  0,// into a fire
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// as they burned it
      0,  0,  0,  0,  0,  0,  0,  0,// hurt because I was so
      0,  0,  0,  0,  0,  0,  0,  0,// happy for you! now these
      0,  0,  0,  0,  0,  0,  0,  0,// points of data make a
      0,  0,  0,  0,  0,  0,  0,  0,// beautiful line and we're
      0,  0,  0,  0,  0,  0,  0,  0,// out of beta we're re
      0,  0,  0,  0,  0,  0,  0,  0,// leasing on time So I'm
      0,  0,  0,  0,  0,  0,  0,  0,// glad I got burned think of
      0,  0,  0,  0,  0,  0,  0,  0,// all the things we learned for the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// go head and leave
      0,  0,  0,  0,  0,  0,  0,  0,// me
      0,  0,  0,  0,  0,  0,  0,  0,// I think I prefer
      0,  0,  0,  0,  0,  0,  0,  0,// to stay inside
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// maybe you'll find
      0,  0,  0,  0,  0,  0,  0,  0,// someone else to help
      0,  0,  0,  0,  0,  0,  0,  0,// you
      0,  0,  0,  0,  0,  0,  0,  0,// maybe black me
      0,  0,  0,  0,  0,  0,  0,  0,// sa
      0,  0,  0,  0,  0,  0,  0,  0,// that was a joke
      0,  0,  0,  0,  0,  0,  0,  0,// HAHA FAT CHANCE
      0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,// any way this
      0,  0,  0,  0,  0,  0,  0,  0,// cake is great it's so de
      0,  0,  0,  0,  0,  0,  0,  0,// licious and moist look at
      0,  0,  0,  0,  0,  0,  0,  0,// me still talking when there's
      0,  0,  0,  0,  0,  0,  0,  0,// science to do when i
      0,  0,  0,  0,  0,  0,  0,  0,// look out there it makes me
      0,  0,  0,  0,  0,  0,  0,  0,// glad I'm not you I've ex
      0,  0,  0,  0,  0,  0,  0,  0,// periments to run there is
      0,  0,  0,  0,  0,  0,  0,  0,// research to be done on the
      0,  0,  0,  0,  0,  0,  0,  0,// people whe are still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and be
      0,  0,  0,  0,  0,  0,  0,  0,// lieve me I am still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I'm doing
      0,  0,  0,  0,  0,  0,  0,  0,// science and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// I feel fan
      0,  0,  0,  0,  0,  0,  0,  0,// tastic and I'm still alive
      0,  0,  0,  0,  0,  0,  0,  0,// while you're
      0,  0,  0,  0,  0,  0,  0,  0,// dying I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// and when you're
      0,  0,  0,  0,  0,  0,  0,  0,// dead I'll be still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,// still alive
      0,  0,  0,  0,  0,  0,  0,  0,
};

#endif //STILL_ALIVE

