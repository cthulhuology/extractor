Yet Another Redesign
====================

For months now, I&#39;ve been delaying work on the full redesign of this site.  The main limitations as I see them are:<ul><li>Turn around time for editing is too long, I need to be able to edit things in place.</li><li>Too many resources tied to the style and presentation of the site itself, still have no good way of embedding code, video, and images.</li><li>Not enough dynamic choice for decorations, I&#39;d like to be able to throw up a bunch of different decorations and have the site randomly and not so randomly adapt to content.</li><li>Need a pretty printer for code that doesn&#39;t suck.</li><li>Still no good way to draw random stuff on the page like one can with pen and paper.</li><li>Inadequate support for touch events</li></ul><br>If you look at the source for one of these pages, you&#39;ll find that there is some stuff to make the iPhone play nicely, a Google Analytics tracker, a big block of text, the ghost text header, and then a html canvas and a list of links.<br><br>It is all very simple.  I edit the pages using a minimalistic wiki format.  (hint it supports lists) and not a full markdown.  I&#39;m leaning very hard towards in the near future ditching that entirely and making the page itself entirely just a static text file. <br><br>Rather than generate some crazy markup or <a href="http://daringfireball.net/projects/markdown/">markdown</a> language, I&#39;ll just write straight text.  By default no real styling will be applied, but that is fine as it makes delivering content very very easy.  If you care more about the presentation than the content, you aren&#39;t going to like what I have to say anyways and will quit reading soon enough.<br><br>But that&#39;s not to say I won&#39;t add style.  I&#39;ve had for months this demo implementation where you can select a region of a page (or just some text) and right click it to bring up a properties tab.  This tab basically allows you to apply arbitrary CSS to that area.  It then uses Javascript to highlight the resulting document with the CSS styling via a third layout JSON.  This is particularly nice as it does a few things:<ul><li>avoids coding stylesheets to build style</li><li>allows me to build gui controls for common elements (color wheels, sliders, etc).</li><li>content knows nothing of semantics, style, or behavior making the job of writing text just about the text.</li></ul><br>This also brings up the next big innovation which will be using a transparent canvas overlay to allow for annotations.  I&#39;d like to be able to add annotations to a page free hand.  I have a bunch of touch devices that can track my writing, and there&#39;s no good reason that I can&#39;t annotate the page as well.  I&#39;d also like the idea of allowing other people to add their annotations to the page.  Since it will require actually using touch gestures (or mouse movements) it has the side effect of making it difficult (but not impossible) for bots to spam.<br><br>The final change is I&#39;m going to switch over to a new HTML + JavaScript web framework based upon the UMPS code.  It will be resource oriented, meaning that Text, Image, Sounds, and Videos will be first class citizens, and style and layout will be strictly separated from the content itself. Also a very simplified Box will model all of the browser box model.<br><br>So while there&#39;s a few style and functionality improvements added today, they&#39;re just stop gaps towards what I really want to work towards.  I need to fix all these linear lists too and navigation as well.  But that will happen when I add the canvas layer, and reduce the entire site to a single page. <br><br>