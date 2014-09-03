#!/usr/bin/env python
# coding: utf-8

import numpy
import matplotlib.pyplot as plt
import scipy.ndimage


def calculate_energy_map(m):
    linhas, colunas = m.shape
    out = numpy.copy(m)
    for i in xrange(1,linhas):
        for j in xrange(colunas):
            vals = [numpy.inf]
            if j > 0:
                vals.append(out[i-1, j-1])
            if j < colunas - 1:
                vals.append(out[i-1, j+1])
            vals.append(out[i-1, j])
            out[i,j] += numpy.nanmin(vals)
    return out


def runalongshortestpath(m,p):
    i = int(p[0])
    j = int(p[1])
    markers = [(i,j)]
    while i > 1:
        minimum = numpy.inf
        jtemp = j
        for offset in xrange(-3,4):
            if m[i-1,j+offset] < minimum:
                minimum = m[i-1,j+offset]
                jtemp = j+offset
        j = jtemp
        i -= 1
        markers.append((i,j))
    return numpy.array(markers)


zoom = 8


data = numpy.genfromtxt('data.csv', delimiter=',', missing_values=['',])
data = numpy.nan_to_num(data)
data = scipy.ndimage.interpolation.zoom(data, zoom)
plt.figure(1)
plt.imshow(data, interpolation='bilinear', cmap="gray")


marker = [47*zoom,20*zoom]
plt.figure(1)
plt.plot(marker[1], marker[0], 'or')


energymap = calculate_energy_map(data)
plt.figure(2)
plt.imshow(energymap, interpolation='nearest', cmap='prism')

path = runalongshortestpath(energymap, marker)
plt.figure(1)
plt.plot(path[:,1], path[:,0], '-', lw=1, ms=2, mew=0, color='yellow')


plt.show()
