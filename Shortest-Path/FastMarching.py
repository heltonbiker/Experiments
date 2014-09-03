#!/usr/bin/env python
# coding: utf-8

import numpy
import matplotlib.pyplot as plt
import scipy.ndimage
import skfmm


zoom = 5


#data = numpy.genfromtxt('data.csv', delimiter=',', missing_values=['',])
#data = numpy.nan_to_num(data)
#data = scipy.ndimage.interpolation.zoom(data, zoom)
##data = 1/(data + data.min() + 0.001)
#data *= 10
#data[-1,:] = -1

data = scipy.ndimage.imread('imagem.jpg', True)

plt.imshow(data, interpolation='bilinear', cmap="gray")

#marker = [47*zoom,20*zoom]
#plt.plot(marker[1], marker[0], 'or')

#phi = numpy.ones_like(data)
#phi[-1,data.shape[1]/4:3*data.shape[1]/4] = -1

#mapa = skfmm.travel_time(phi, data*50)
#print mapa
#plt.imshow(mapa, interpolation='nearest', cmap='flag')


plt.figure()
mapa = skfmm.distance(data)
#mapa = skfmm.travel_time(mapa[mapa==mapa.max()], mapa)
plt.imshow(mapa, interpolation='nearest', cmap='gray')

#path = runalongshortestpath(energymap, marker)
#plt.plot(path[:,1], path[:,0], '-', lw=1, ms=2, mew=0, color='yellow')


plt.show()
