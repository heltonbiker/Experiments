#!/usr/bin/env python
# coding: utf-8

import numpy

def distance (p1, p2):
    return ((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)**0.5

def snap_to_segment(p, s):
     
    P = numpy.array(p).flatten()
    s1 = numpy.array(s[0]).flatten()
    s2 = numpy.array(s[1]).flatten()
    
    v = s2 - s1
    w = P - s1

    c1 = numpy.dot(w,v)
    c2 = numpy.dot(v,v)
    
    if c1 <= 0:
        r = distance(P, s1)
        pt, dist = s1, r

    elif c2 <= c1:
        r = distance(P, s2)
        pt, dist = s2, r
    
    else:
        mid = s1 + v * (c1 / c2)
        r = distance(P, mid)
        pt, dist = mid, r
    return pt, dist
    
    
def snap_to_polyline(p, poly):
    shortest = numpy.inf
    snap = None
    
    for n in xrange(1, len(poly)):
        P, D = snap_to_segment(p, (poly[n-1], poly[n]))
        if D < shortest:
            snap = P
            shortest = D

    return snap, shortest


if __name__ == "__main__":

    def plota(pline, *args, **kwargs):
        pline = numpy.asarray(pline).reshape(-1,2)
        plt.plot(pline[:,0], pline[:,1], *args, **kwargs)

    import matplotlib.pyplot as plt
    import numpy
    
    
    bbox = numpy.array([[0,0], [20, 10]])
    scale = numpy.array([20,10])


    plt.figure()
    plota(bbox, 'o')

    s1 = (5, 5)
    s2 = (15,5)

    seg = numpy.array((s1, s2))
    plota(seg, '-', lw=3, alpha=0.5, color='r')

    for n in xrange(30):
        pr = numpy.random.random((1,2)) * scale
        plota(pr, 'o', ms=3, mew=0, color='b')
        
        snapped, _ = snap_to_segment(pr, (s1, s2))
        snapseg = numpy.vstack([pr, snapped])
        plota(snapseg, '-')
    
    plt.axis('image')



    plt.figure()
    plota(bbox, 'o')
    
    #pline = [numpy.random.random((1,2)) * scale for _ in xrange(10)]
    
    pline = []
    pline.append((1,1))
    pline.append((3,2))
    pline.append((5,8))
    pline.append((8,5))
    pline.append((11,4))
    pline.append((10,7))
    pline.append((14,8))
    pline.append((13,6))
    pline.append((8,9))
    
    plota(numpy.vstack(pline), '-', lw=3, color='orange')

    for n in xrange(30):
        pr = numpy.random.random((1,2)) * scale
        plota(pr, 'o', ms=3, mew=0, color='b')
        
        snapped, _ = snap_to_polyline(pr, pline)
        snapseg = numpy.vstack((pr, snapped))
        plota(snapseg, '-', lw=1, alpha=0.5)

    plt.axis('image')


    plt.show()

