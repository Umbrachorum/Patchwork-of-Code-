/***********
 	***************
		 			FRONT JAVASCRIPT ********************
										*******************/

function docReady(fn) {
	if (document.readyState === "complete" || document.readyState === "interactive") {
		setTimeout(fn, 1);
	} else {
		document.addEventListener("DOMContentLoaded", fn);
	}
}

function returnJob(job, i) {
	let htmlJob = `<div class="row">
					<div class="col s12 m12 l10 offset-l1">
						<div class="card job">
							<div class="card-image waves-effect waves-block div-job-title">
								<h3 class="jobtitle"> ${job.title}</h3>
							</div>
							<div class="card-content">
								<span class="card-title activator grey-text text-darken-4">${job.company_name}<i
										class="right">learn more</i></span>
								<p>${job.description}</p>
							</div>
							<div class="card-reveal">
								<span class="card-title grey-text text-darken-4">${job.title}<i
								class="material-icons right">close</i></span>
								<div class="custom_card_job">
									<div>
										<h4>Description</h4>
										<p>${job.description}</p>
										<h4>Wages</h4>
										<p>${job.salary} €</p>
										<h4>Where it takes place</h4>
										<p>${job.city_name}</p>
										<h4>Activity area</h4>
										<p>${job.parent_field_name}: ${job.child_field_name}</p>
										<h4>Worktime</h4>
										<p>${job.worktime} hours / week</p>
									</div>
									<div class="button_container">
									<a href="#modal${i}" class="modal-trigger btn-large waves-effect waves-light purple lighten-1">Apply now !
										<i class="material-icons right">send</i>
									</a>
									</div>
								</div>
							</div>
						</div>
					</div>
				</div>`;
	return htmlJob;
}

function display_jobs() {

	return getter("jobs").then((response) => {

		return new Promise((resolve) => {
			for (let i = 0; i < response.length; i++) { 
	
				document.querySelector("main div.container").innerHTML += returnJob(response[i], i);
				initApplyForm(response[i].id, response[i].company_id, i);
			}
			resolve();
		});
	});
}

// const infinite_scroll = (fn) => {
// 	window.addEventListener("scroll", () => {
// 		// console.log(window.scrollY); //scrolled from top
// 		// console.log(window.innerHeight); //visible part of screen
// 		if (window.scrollY + window.innerHeight >= document.documentElement.scrollHeight) {
// 			fn();
// 		}
// 	});
// };

function sidenav() {
	var sidenav_elems = document.querySelectorAll('.sidenav');
	var sidenav_instances = M.Sidenav.init(sidenav_elems, {preventScrolling: true});
}

docReady(() => {
	display_jobs()
	.then(() => {
		initModals();
	});
	sidenav();
});