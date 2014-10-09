# Description

A Python wrapper to the lambert C library.

# Usage

```python
import lambert

# Declares origin point and translated point
a = lambert.Point(994300.623, 113409.981)

# Converts a in Lambert Zone 1 to WGS84 - Results in Radian
a.wgs84deg(lambert.LambertI)

print "Latitude:{} Longitude:{}".format(a.y, a.x)

```

#License
Copyright (c) 2013 Yannick Heinrich - Released under the GPLv2 License.
