Riak, haproxy, and client side applications
===========================================

Last night I switched my local PhosGL development from a django app to running a riaksearch cluster fronted by haproxy. The amount of change required was mapping the old urls to the new riak buckets. I created buckets for objects, images, sounds, shaders, and models. I also created an application bucket that serves the default HTML document. The immediate advantage of this is I can now have JavaScript PUT new documents directly into the riak key value store. For primay source control, I have a git-hook which calls the &#39;make install&#39; script which rebuilds the MANIFEST file, revs it&#39;s version, and curls all of the files in version control into their appropriate buckets. <br /><br />Currently since this deployment scheme is destructive, rolling back changes is just a matter of reversing the commit and having the make install command run. In the not too distant future I&#39;m going to integrate a UUID script to generate universally unique ids for each object in the datastore, and use a client side router object which manages mapping canonical names to UUIDs. <br /><br />The advantage here is that publishing a single routing table is all that is necessary to do a release, and reverting changes just amounts to pushing the old route object. The other very clever bit is I can publish a timeline object which contains routes to all the previous route objects, and run the app as it existed at any point in time. <br /><br />Since I already have a module loader and data access layer, it only requires a minimal prefetch and one indirection in the use method to imement. This same interface can also support PUT for revisions of objects wherein each revision merely puts a new object and the UUID mapping can generate future routes and not deploy them. This way I can build for a future release in place and it will simply be a matter of updating the canonical route object with the appropriate UUID. <br /><br />This is obviously really simple, as we only use HTTP GET and PUT. Riak handles distribution, and haproxy multiplexes and loadbalances. But the coolest bit is search. Because I am storing code and data in a Solr indexed key value store, my application can discover documents and objects via search. More over using a got-hook to publish diffs to the key value store allows us to search for changes.  Finally since every entity will have a UUID, it is possible to search for every version of an object that ever implemented or called a method, protocol, or referenced a static or global entity. <br /><br />Once the WebGL editor is nice enough with a subset of vi commands my fingers refuse to unlearn, I will probably stop using git entirely. This will mean implementing diff in JavaScript, but someone has probably done that already.