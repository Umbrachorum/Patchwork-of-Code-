const infinite_scroll = (fn) => {
	window.addEventListener('scroll',()=>{
		console.log(window.scrollY) //scrolled from top
		console.log(window.innerHeight) //visible part of screen
		if(window.scrollY + window.innerHeight >=
			document.documentElement.scrollHeight){
			fn(10);
		}
	});
}

function docReady(fn) {
	// see if DOM is already available
	if (document.readyState === "complete" || document.readyState === "interactive") {
		// call on next available tick
		setTimeout(fn, 1);
	} else {
		document.addEventListener("DOMContentLoaded", fn);
	}
} 

function display_components(n) {
	for(let i=0; i < n; i++) {
		document.querySelector("main div.container").innerHTML += 
				`<div class="row">
					<div class="col s12 m12 l12">
						<div class="card job">
							<div class="card-image waves-effect waves-block waves-light">
								<h3 class="jobtitle"> Job title </h3>
							</div>
							<div class="card-content">
								<span class="card-title activator grey-text text-darken-4">Job title<i
										class="right">learn more</i></span>
								<p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Magnam quis ipsa expedita placeat iure ab iste molestias rerum beatae odio eveniet, dolorum et, explicabo nisi in consequatur maxime eaque accusantium?</p>
							</div>
							<div class="card-reveal">
						<span class="card-title grey-text text-darken-4">Job title<i
								class="material-icons right">close</i></span>
								<h4>Description</h4>
								<p>Here is some more information about this job that is only revealed once clicked on.</p>
								<h4>Wages</h4>
								<p>Here is some more information about this job that is only revealed once clicked on.</p>
								<h4>Working Time</h4>
								<p>Here is some more information about this job that is only revealed once clicked on.</p>
								<h4>Field</h4>
								<p>Here is some more information about this job that is only revealed once clicked on.</p>
								<h4>Other infos</h4>
								<p>Here is some more information about this job that is only revealed once clicked on.</p>
							</div>
						</div>
					</div>
				</div>`;
	}
}

function sidenav() {
    var elems = document.querySelectorAll('.sidenav');
    var instances = M.Sidenav.init(elems, {preventScrolling: true});
}

docReady(() => {
	display_components(10);
	// infinite_scroll(display_components);
	sidenav();
});