epaMote
=======

Cheap, low-power and small wireless sensor nodes.

# Packet Header

  type|ID|timestamp


# Packet Types

|type| Description                     |
|----|---------------------------------|
| B0 | Boot ID request                 |
| 1D | ID response                     |
| DA | Sensor data                     |
| ED | Transition to epidemic state    |
| A0 | Transition to online mesh state |
| 5D | Software download to node       |


# Node types

|type| Description                     |
|----|---------------------------------|
| 00 | Plain node, no sensor           |
| 01 | Server node                     |
|           Display Nodes              |
| 10 | Basic 16x2 LCD display node     |
| 11 | Text display node               |
| 12 | Graphics display node           |
|         Temperature Nodes            |
| 20 | Plain temperature sensor node   |
| 21 | High temperature node           |
| 22 | Extremely high temperature      |
| 23 | Low temperature node            |
| 24 | Extremely low temperature node  |
|             Light Senors             |
| 30 | Plain light node                |
| 31 | Infrared node                   |
| 32 | Ultraviolet node                |
|           Humitidy Sensors           |
| 40 | Air humidity                    |
| 41 | Soil humidity                   |
| ...                                  |


# Joining the Network

  When a device boots, it sends a discover packet on queue
  0x7E7E7E7E7E, containing 0xB0|0x07|node type.

  A nearby server picks it up and sends a discover response
  on queue 0x7E7E7E7E7D, containing 0x1D|assigned ID|timestamp.


# Epidemic Sensor Reporting

  A node wakes up from deep sleep, gathers sensor data and
  sends one packet per sensor value in the format:
  0xDA|ID|timestamp|value
