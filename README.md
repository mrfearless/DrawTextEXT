# DrawTextEXT
Extended DrawText function with html and bbcode support

Adapted from DrawHTML code posted by Ukkie9:  https://www.codeproject.com/Articles/7936/DrawHTML

[![](https://img.shields.io/badge/Assembler-MASM%206.14.8444-brightgreen.svg?style=flat-square&logo=visual-studio-code&logoColor=white&colorB=C9931E)](http://www.masm32.com/download.htm) [![](https://img.shields.io/badge/RadASM%20-v2.2.2.x%20-red.svg?style=flat-square&colorB=C94C1E&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAgCAYAAAASYli2AAACcklEQVR42tWVXWiPURzHz/FyQZOiVuatuFEoKzfKSCs35EJeCqFcEEa5s2heNrXiApuXFDYveUlKSywlIRfczM0WjZvJlGKTRLb5fHvOU6fT+T/PY3bj1Kff8z8vn+f8znPO+dshihnBYv8L4awRcl2FRTarBy8bQzgEjdbabzl9nxCW2IwOFYTrsBTKEH7PET4lLLYlGpcTrkC5qxqL8HeO8CVhoQ0qRxMOw34Y5TVVIPyYI+whTLVehZ9iWgZAL1mN8G6GbArhA/TZEilqKx2HCbADXkAV0oESwhOEfdChbXOUh1ovxS+wlcH3aNvC82VX3wx7Qyl9NhEugXZEU7ixX8E6Br13nTVDPU927R3QCl0wTX2h2rUNQqUv/ATLkHUGM1hLuBF8pFipZ+zBcIZKpw1O0vjYk24mnIXxEZHGNMIBxgxJ2M2P2PF7DafhGh1/0G8Gzzv1cWASfIZn0EJ7VzpIQqWyUguulFUXiDXwApxhYE9O2ibc2PMJNbAxkp5Oyh3NGvHzQkJPrK/aANtLjNNuOAU3kf/KFTrpGsJtaIdxbu3C0gvn4Dzi3qLCI3Su4/cCnnfDBvcCv/yEW0a7o6gwWI5tJvniMwutYZbQa9elsUqzgun/JKStjKAzvAvmDXuG1M1xqerkTAyG6Cy3FREeM8k2kag6MomvcBGaefG7LOF6k1wK6SUbFl0iOpqt/v+NjYjmEva4NQpPi9K6b5JN/UiXQTg+vbF1nlc4USytPpNcok1Iuk1G0eWgS0Hnd3akXbeIbuqWvP9lXxhOW2k9cOvzMJZWUWG/Sf4/lNbbv5GEwjeSSIaof7iitPwBoSgbVud1Jo0AAAAASUVORK5CYII=)](http://www.softpedia.com/get/Programming/File-Editors/RadASM.shtml) ![](https://img.shields.io/badge/Win32%20API-GDI-blue.svg?style=flat-square&logo=windows&logoColor=white) ![](https://img.shields.io/badge/Architecture-x86-lightgrey.svg?style=flat-square&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEAAAABACAQAAAAAYLlVAAAC1UlEQVR42u3WA9AjWRSA0bu2bdu2bdssrm3btm3btm3bmX+Ms7rLTiW9NUmvcsL7XuELu6Ojoz5DWcc5nvKp2kBdPvesi21m1Pgr7OxjrfWtgw0VZZjKM9rjXfNHM+bWWzutGo2YSH/tNm+jgNe1XzdDR322V41Tox5D6K4qY0WRtVRnjyhysercH0VeVJ13o8hXqvNNFOlSna4oUlOd2r8moBPwoQfd6THfoLweauqp6aJ8wInmMmjujWAFtwMeNJup5cXsVnWYDyDtajQjmMp7QOoypxGMbMtyAe+Ztf5/JTaJAkM6mjRXrj0KpE9zdZIyAV8bLX5lBIPlszXAVlGXMwAr5fwskL4wdPzAfGUC5o9kJy+o+dCVloiwJNg2907wimddZrqcB9GtNQF3RXI+kI5yCcgADwF6yvfLNa0JWD7n5dWXAa4lbZwrR7UioKdhc76vdEB+KxzbioAncxpGr9IBM+XKDa0IuCanaWkS8BzguEhqrQg4P6e5mgasbV+7WCySvWlFwIU5zdYooMhytCbghpzGLh9gAodCWjFXXwDSV4aJH5inWcBLkbzTOMBa9rWvk92jH5BWqBvwjSHKBfQ3as4HlvoSFq2b+zcB6bXIj6pZABvnPKzPgPSJlxV/hkUH5v7SUPiv2LN5wKuRjO82wDdON6xFSwW8XvhdcGYkrzUPYJf4lcktZh4jxg8sViqA9SKZxDo2NH0km1ImgE2jDjuBLXK6FPX1N1fUYQnKBnCeGeN3jGdPfUC+P27TyO7GjN8xoUMpHZCecKZ97etE9+hD6vKQOz1jgMa6u90J+VO9V//OaXnzgE5Al+p0iyLfqM63UeRV1Xk/ilylOo9Gkc1U55AoMrz+qjJJ1OMQ1bgq6jOYr1Rh9EgFZtd+q0QjVtFeW0UzFvGJ9uhhrSjDSE7UX6tdaMIoz0R2cbvXfKE2UJevvOEe+5kuOjr+qb4H0/HV/SQ0YjEAAAAASUVORK5CYII=) [![](https://img.shields.io/badge/Buy%20Me-A%20Coffee-orange.svg?style=flat-square&colorB=F19B55&logo=data:image/png;base64,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)](https://www.buymeacoffee.com/mrfearless)

## Setup DrawTextEXT

* Download the latest version of the DrawTextEXT release and extract the files. The latest release can be found in the [releases](https://github.com/mrfearless/DrawTextEXT/tree/master/releases) folder, or can be downloaded directly from [here](https://github.com/mrfearless/DrawTextEXT/blob/master/releases/DrawTextEXT.zip?raw=true).
* Copy the `DrawTextEXT.inc` file to your project's folder
* Copy the `DrawTextEXT.asm` file to your project's folder
* Add the following to your project: `include DrawTextEXT.asm`
* Call the `DrawHTMLCODE` or `DrawBBCODE` function in your code, preferably in a control's `WM_PAINT` event.


## DrawTextEXT Supported Tags

**DrawHTMLCODE:**

The `DrawHTMLCODE` function supports the following html tags, enclosed in angle brackets `<>` for starting tags and `</>` for ending tags:

* `<b> </b>`, `<strong> </strong>` for bolding text 
* `<i> </i>`, `<em> </em>` for italic text
* `<u> </u>` for underlined text
* `<sub> </sub>` for subscript
* `<sup> </sup>` for superscript
* `<pre> </pre>`, `<code> </code>` for preformatted text
* `<br>` for line breaks
* `<p>` for paragraph breaks
* `<font color='#RRGGBB'> </font>` for color of text using a hex string
* `<color='#RRGGBB'> </color>` for color of text using a hex string
* `<q> </q>`, `<quote> </quote>`, `<blockq> </blockq>` for block quotes
* `<ul> </ul>` for unordered lists with bullets
* `<ol> </ol>` for ordered lists with numbers
* `<li> </li>` for list items within a list
* `<hr> </hr>` for horizontal rule
* `<a href='url'>title</a>` for hyperlinks having a url and title

**Note:** Strings that include byte sequences of `13,10` (`0D,0Ah`) known as CRLF or `10` (`0Ah`) known as LF, **ARE IGNORED**. Use the `<br>` or `<p>` if you wish to break to a new line.

`<a>` tag supports internal ids if prefixed with a `#`, for example: 

```
Click on this <a href="#1010">link</a> to show a message box
```

The url title text is shown as 'link' and the id as `#1010`. When the url is  clicked, the id will be converted to an integer (`1010`) and send to the parent window via the `WM_COMMAND` message with the id integer stored in the high word of `wParam` 



**DrawBBCODE:**

The `DrawBBCODE` function supports the following bbcode tags, enclosed in square brackets `[]` for starting tags and `[/]` for ending tags:

* `[b] [/b]`, `<strong> </strong>` for bolding text 
* `[i] [/i]` for italic text
* `[u] [/u]` for underlined text
* `[code] [/code]` for preformatted text
* `[color=#RRGGBB] [/color]` for color of text using a hex string
* `[q] [/q]`,` [quote] [/quote]` for block quotes `*`
* `[ul] [/ul]` for unordered lists with bullets
* `[ol] [/ol]` for ordered lists with numbers
* `[li] [/li]` or `[*]` for list items within a list
* `[url] [/url]` for hyperlinks having a url and title

`*`Experimental/Not Complete

**Note:** There is no bbcode for line breaks or paragraph. Strings that include byte sequences of `13,10` (`0D,0Ah`) known as CRLF or `10` (`0Ah`) known as LF, are automatically processed to break to a new line.

`[url]` tag supports internal ids if prefixed with a `#`, for example: 

```
Click on this [url=#1010]link[/url] to show a message box
```
The url title text is shown as 'link' and the id as `#1010`. When the url is clicked, the id will be converted to an integer (`1010`) and send to the parent window via the `WM_COMMAND` message with the id integer stored in the high word of `wParam` 



## DrawTextEXT Demo

A RadASM example project is included to demonstrate the `DrawHTMLCODE` function. It can be found in the [releases](https://github.com/mrfearless/DrawTextEXT/tree/master/releases) folder, or can be downloaded directly from [here](https://github.com/mrfearless/DrawTextEXT/blob/master/releases/DrawHTMLTest.zip?raw=true).



## Additional Resources

* [RadASM IDE](http://www.softpedia.com/get/Programming/File-Editors/RadASM.shtml)
* [Masm32](http://www.masm32.com/download.htm)
* [UASM](http://www.terraspace.co.uk/uasm.html)

If you like this project and would like to support me, consider buying me a coffee: [buymeacoffee.com/mrfearless](https://www.buymeacoffee.com/mrfearless)