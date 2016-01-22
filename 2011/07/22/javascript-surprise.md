Javascript Surprise
===================

Last night I was working on implementing binary messages for my <a href="http://github.com/cthulhuology/Self.js">Self.js</a> project. The issue with binary message sends is that the right hand side is effectively part of the message. If you think of the simple case:<br><br>  1 + 2<br><br>The object 1 is receiving a message + and that product then receiving the message 2:<br><br>  ((1 +) 2)<br><br>Or the + message holds an implicit parameter such that :<br><br>  [1,&#39;+&#39;,2].eval()<br><br>Will produce:<br><br>  3<br><br>For sake of simplicity I went down the later, as it posed an interesting question:<br><br>  "Would JavaScript built in objects be extensible enough to implement message sending?"<br><br>Now I know it is easy to generate a function object to evaluate a partial application. Most of Self.js relies on the production of closure functions from dynamic sources. The interesting question was did the language implementers build their engine such that:<br><br>  1[&#39;+&#39;](2) == 3<br><br>So far the answer is "yes on Safari".  I started off this exploration with this code:<br><br>  Number.does(&#39;+&#39;, function(y) { return this + y*1 })<br><br>The &#39;does&#39; function merely walks the argument list assigning slots in the object&#39;s prototype. The name was inspired by create does> in Forth, but is just a nice readable way to extend a base prototype. It turns out that this is all that is needed to get the message send to work. <br><br>But that&#39;s not all!  We need our Lisp like structure to evaluate the representation:<br><br>  Array.does(&#39;eval&#39;, function() { var self = eval(this[0]); return self[this[1]].apply(self,this.after(1)) })<br><br>This has the super awesome ability to turn an array of strings into a self evaluating Array. <br><br>  &#39;1 +  2&#39;.split(/\\s+/).eval()<br><br>Will transform the string into an array:<br><br>  [&#39;1&#39;,&#39;+&#39;,&#39;2&#39;]<br><br><br>Which will then eval &#39;1&#39; to 1 and invoke <br><br>  1[&#39;+&#39;](2)<br><br>Via apply which will call<br> <br>  function(y) { return this + y*1 }<br><br>Where this === 1 and y === &#39;2&#39;<br><br>And while this looks like a long way to go to add two numbers, it shows how one can represent program in Json, and perform dynamic dispatch to functions which "fix" builtin behavior. <br><br>I have gone on to implementing a whole host of infix operators. <br><br>Next step partial application and macros :)<br><br><br>