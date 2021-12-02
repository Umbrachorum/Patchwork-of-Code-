function returnJob(job, i) {
	let htmlJob = `<div class="row">
		<div class="col s12 m12 l10 offset-l1">
			<div id="card${i}" class="card job">
				<div class="card-image waves-effect waves-block div-job-title">
					<h3 class="jobtitle"> ${job.title}</h3>
				</div>
				<div class="card-content">
					<span class="card-title grey-text text-darken-4">${job.company_name}</span>
					<p id="desc_hidden">${job.description}</p>
					<div>
						<button id="learn_more${i}" class="activator waves-effect btn-flat learn_more">Learn more
							<i class="material-icons right">more_horiz</i>
						</button>
					</div>
				</div>
				<div class="card-reveal">
					<div id="close_reveal${i}" class="card-title grey-text text-darken-4">${job.title}<i class="material-icons right">close</i></div>
					<div class="custom_card_job">
						<div class="job_desc">
							<div>
								<h4>Activity area</h4>
								<p>${job.parent_field_name}: ${job.child_field_name}</p>
								<h4>Wages</h4>
								<p>${job.salary} €</p>
							</div>
							<div>								
								<h4>Worktime</h4>
								<p>${job.worktime} hours / week</p>
								<h4>Place</h4>
								<p>${job.city_name}</p>
							</div>
						</div>
						<div>
							<h4>Description</h4>
							<p id="desc">${job.description}</p>
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

async function clearJobs() {
	document.querySelector("main div.container").innerHTML = "";
	return;
}

async function clearModals() {
	document.querySelector("div#modals_div").innerHTML = "";
	return;
}

async function cardsMobile(i) {	
	if(document.querySelector("body").clientWidth <= 576) {
		document.querySelector(`button#learn_more${i}`).addEventListener('click', function () {
			document.querySelector(`div#card${i}`).style.height = "750px";
		});
		document.querySelector(`div#close_reveal${i}`).addEventListener('click', function () {
			document.querySelector(`div#card${i}`).style.height = "550px";
		});
	} else if (document.querySelector("body").clientWidth > 576) {
		document.querySelector(`button#learn_more${i}`).addEventListener('click', function () {
			document.querySelector(`div#card${i}`).style.height = "570px";
		});
		document.querySelector(`div#close_reveal${i}`).addEventListener('click', function () {
			document.querySelector(`div#card${i}`).style.height = "420px";
		});
	}
}

function appendJob(response, i) {
	return new Promise(resolve => {
		document.querySelector("main div.container").innerHTML += returnJob(response.data[i], i);
		resolve();
	});
}

function display_jobs() {

	var page = 1;
	if(window.sessionStorage.getItem('page') !== undefined && window.sessionStorage.getItem('page') !== null) {
		page = window.sessionStorage.getItem('page');
	} else {
		window.sessionStorage.setItem('page', page);
	}
		
	return getter(`jobs?page=${page}`).then((response) => {
		return new Promise(async (resolve) => {
			await clearJobs();
			await clearModals();
			for (let i = 0; i < response.data.length; i++) {
				appendJob(response, i)
				.then(async function () {
					let modalOK = await initApplyForm(response.data[i].id, response.data[i].company_id, i);
					cardsMobile(i);
				});
			}
			window.sessionStorage.setItem('pages_total', response.total);
			resolve();
		});
	});
}

function nav_working()
{
	draw_navbar();
	job_button();
	choose_url_profile();
	sidenav();
	select_login_logout();
}

docReady(() => {
	nav_working();
	display_jobs()
	.then(() => {
		initModals();
		initPages(window.sessionStorage.getItem('pages_total'));
		initActivePage();
	});
	logout();
});