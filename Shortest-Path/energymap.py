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


def runalongshortestpath(m):
    i = m.shape[0]-1
    j = numpy.argmin(m[i,:])
    markers = []
    while i > 1:
        minimum = numpy.inf
        jtemp = j
        for offset in xrange(-1,2):
            jnow = j+offset
            if jnow >= 0 and jnow < m.shape[1] and m[i-1,jnow] < minimum:
                minimum = m[i-1,jnow]
                jtemp = jnow
        j = jtemp
        i -= 1
        markers.append((i,j))
    return numpy.array(markers)



data = scipy.ndimage.imread('imagem.jpg', True)
print data.shape
#data = numpy.genfromtxt('data.csv', delimiter=',', missing_values=['',])
#data = numpy.nan_to_num(data)
#zoom = 8
#data = scipy.ndimage.interpolation.zoom(data, zoom)


#marker = [47*zoom,20*zoom]
#plt.plot(marker[1], marker[0], 'or')


energymap = calculate_energy_map(data)
plt.figure()
plt.imshow(energymap, interpolation='nearest', cmap="gray")

path = runalongshortestpath(energymap)
plt.plot(path[:,1], path[:,0], '-', lw=1, ms=2, mew=0, color='yellow')

plt.figure()
plt.imshow(data, interpolation='nearest', cmap="gray")
plt.plot(path[:,1], path[:,0], '-', lw=1, ms=2, mew=0, color='yellow')


plt.show()
