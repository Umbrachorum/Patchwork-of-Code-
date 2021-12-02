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
					<div class="col s12 m10 l10">
						<div class="card job">
							<div class="card-image waves-effect waves-block">
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

function returnModal(i) {
	let htmlModal = `<div id="modal${i}" class="modal modal-fixed-footer">
						<div class="modal-content">
							<form class="col s12">
								<h4>About you</h4>
								<div class="row">
									<div class="input-field col s6">
										<input id="first_name${i}" type="text" class="validate">
										<label for="first_name${i}">First Name</label>
									</div>
									<div class="input-field col s6">
										<input id="last_name${i}" type="text" class="validate">
										<label for="last_name${i}">Last Name</label>
									</div>
								</div>
								<div class="row">
									<div class="input-field col s12">
									<input id="email${i}" type="email" class="validate">
									<label for="email${i}">Email</label>
									</div>
								</div>
								<div class="row">
									<div class="input-field col s6">
										<i class="material-icons prefix">phone</i>
										<input id="telephone${i}" type="tel" class="validate">
										<label for="telephone${i}">Telephone</label>
									</div>
								</div>
								<h4>Send your CV and motivation letter</h4>
								<div class="row">
									<div class="col s12 m6 l6">
										<div class="file-field input-field">
											<div class="btn purple lighten-1">
												<span>CV</span>
												<input id="cv${i}" type="file">
											</div>
											<div class="file-path-wrapper">
												<input class="file-path validate" type="text">
											</div>
										</div>
									</div>
									<div class="col s12 m6 l6">
										<div class="file-field input-field">
											<div class="btn purple lighten-1">
												<span>Letter</span>
												<input id="letter${i}" type="file">
											</div>
											<div class="file-path-wrapper">
												<input class="file-path validate" type="text">
											</div>
										</div>
									</div>
									
								</div>
								<h4>Write a message</h4>
								<div class="row">
									<div class="input-field col s12">
									<textarea id="textarea${i}" class="materialize-textarea"></textarea>
									<label for="textarea${i}">Your message</label>
									</div>
								</div>
							</form>
							<a href="#!" id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
								<i class="material-icons right">send</i>
							</a>
						</div>
						<div class="modal-footer">
							<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
						</div>
					</div>`;
	return htmlModal;
}

function initApplyForm(job_id, company_id, i) {
	document.querySelector("main").innerHTML += returnModal(i);

	// document.querySelector(`a#send_btn${i}`).addEventListener("click", () => {
	// 	sendApplyForm(job_id, company_id, i);
	// });
}

function sendApplyForm(job_id, company_id, i) {
	let message = document.querySelector(`textarea#textarea${i}`).innerText;
	
	let req = {
		"message": message,
		"cv": null,
		"motivation_letter": null,
		"job_id": job_id,
		"company_id": company_id
	}	

	let body = JSON.stringify(req);

	postReq("job_applications", body);
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
	let sidenav_elems = document.querySelectorAll(".sidenav");
	var sidenav_instances = M.Sidenav.init(sidenav_elems, { preventScrolling: true });
}

function initModals() {
	let modal_elems = document.querySelectorAll(".modal");
	var modal_instances = M.Modal.init(modal_elems);
}

docReady(() => {
	display_jobs()
	.then(() => {
		initModals();
	});
	sidenav();
});
