# DrawTextEXT
Extended DrawText function with html and bbcode support

Adapted from DrawHTML code posted by Ukkie9:  https://www.codeproject.com/Articles/7936/DrawHTML

[![](./assets/Assembler-MASM_6.14.8444.png)](http://www.masm32.com/download.htm) [![](./assets/RadASM-v2.2.2.x.png)](http://www.softpedia.com/get/Programming/File-Editors/RadASM.shtml)![](./assets/Win32_API-GDI.png) ![](./assets/Architecture-x86.png) [![](./assets/Buy_Me-A_Coffee.png)](https://www.buymeacoffee.com/mrfearless)

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

The `DrawBBCODE` function supports the following bbcode tags, enclosed in aquare brackets `[]` for starting tags and `[/]` for ending tags:

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