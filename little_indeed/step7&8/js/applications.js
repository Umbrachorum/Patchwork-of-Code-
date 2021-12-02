function returnApplicationJob(user, i) {
	let htmlApplication = `<div class="row">
		<div class="col s12 m12 l12">
		  <div class="col s12 m6 l6 offset-m3 offset-l3">
			<div id="card${i}" class="card blue-grey darken-1">
				<div class="card-content white-text">
					<span class="card-title">Candidature au poste de : ${user.job_title}</span>
					<p>${user.message} </br> ${user.user_email} </br>${user.user_lastname} ${user.user_firstname}</p>
				</div>
				<a id="decline_app${i}" href="#!" class="waves-effect btn-flat modal_button_validation"> Decline
				<i class="material-icons right">Decline</i></a>
			</div>
		</div>
	</div>
	</div>`;
	return htmlApplication;
}

function decline (i, id){
    let del_button = document.querySelector(`a#decline_app${i}`);
    var token = JSON.parse(window.sessionStorage.getItem('companies')).token;
    del_button.addEventListener("click", async function(){
        delReq(`job_applications/${id}`, token)
            .then((response) => {
                redirect_to_company_protection();
            })
            .catch(error => console.log(error));
    });
}

async function clearJobs() {
	// document.querySelector("main div.container").innerHTML = "";
	return;
}

async function clearModals() {
	// document.querySelector("div#modals_div").innerHTML = "";
	return;
}

function getterByToken(path, token) {
	return new Promise((resolve, reject) => {
		fetch(`http://localhost:8000/api/${path}`, {
			method: "GET",
			headers: {
				"Content-Type": "application/json",
				"Accept": "application/json",
				'Authorization': 'Bearer ' + token
			},
		})
		.then((response) => response.json())
		.then((data) => resolve(data))
		.catch(reject);
	});
}

function getAllApplication() {
	let companies = window.sessionStorage.getItem(`companies`);
	let id = JSON.parse(companies).companies.id;
	let token = JSON.parse(companies).token;
	console.log(id);
	return getterByToken(`job_applications/single/${id}`, token).then((response)=>{
		return new Promise((resolve, reject) => {
			console.log(response);
			for (let i = 0; i < response.length; i++) {
				document.querySelector("section.container.section").innerHTML += returnApplicationJob(response[i], i);
				//decline(i, response[i].id);
			}
			resolve();
		})
	});
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
	const companyId = JSON.parse(window.sessionStorage.getItem('companies')).companies.id;
	return getter(`job_applications/${companyId}`).then((response) => {
		return new Promise(async (resolve) => {
			await clearJobs();
			await clearModals();
			for (let i = 0; i < response.length; i++) {
				appendJob(response, i)
				.then(async function () {
					// cardsMobile(i);
				});
			}
			window.sessionStorage.setItem('index_job_number', response.total);
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

function nav_working()
{
	draw_navbar();
	choose_url_profile();
	sidenav();
	select_login_logout();
}

docReady(() => {
	nav_working();
	getAllApplication()
	.then(() => {
	});
	logout();
});