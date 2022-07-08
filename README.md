# mediatracker
sort and track your media
## Getting Started
### dependences
* [jtbl](https://github.com/kellyjonbrazil/jtbl)
* [json-c](https://github.com/json-c/json-c)
### Installing
```
git clone https://github.com/Hauptling12/mediatracker
cd mediatracker
mkdir ~/.local/share/mediatracker/ && cp data.json ~/.local/share/mediatracker/
gcc mediatracker.c -ljson-c -o mediatracker
cp mediatracker ~/.local/bin
```
## man page
+ `-a` add media
+ `-l` list media
+ `-h` show the man page
