# ARTDSL INCLUDE LIBRARY FOR SA-MP & OPEN.MP


**Last Update:** 30/04/2022

## Wiki

[Click here](https://github.com/ArTDsL/ARTDSL-ICL-SAMP/wiki) to access _**ARTDSL INCLUDE LIBRARY**_ wiki.

## How to install

_**SA-MP**_

- Create a folder name `ARTDSL` in your `includes` folder;
- Copy all `.inc` files to that folder;
- Include `ARTDSL/ART.inc` in your gamemode header;
```pawn
#include    <ARTDSL/ART.inc>
```
- Copy **ARTDSL.dll**(_Windows_)/**ARTDSL.so**(_Linux_) into `plugins` folder, on samp server $root;
- Reference `ARTDSL` on `plugins` line in your `server.cfg` file.

_**OPEN.MP**_

- Create a folder name `ARTDSL` in your `includes` folder;
- Copy all `.inc` files to that folder;
- Include `ARTDSL/ART.inc` in your gamemode header;
```pawn
#include    <ARTDSL/ART.inc>
```
- Copy **ARTDSL.dll**(_Windows_)/**ARTDSL.so**(_Linux_) into `components` folder, on omp server $root;
- Reference `ARTDSL` on `server.cfg`/`config.json`.
