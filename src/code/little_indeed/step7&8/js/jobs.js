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
										<h4>Place</h4>
										<p>${job.city_name}</p>
										<h4>Activity area</h4>
										<p>${job.parent_field_name}: ${job.child_field_name}</p>
										<h4>Worktime</h4>
										<p>${job.worktime} hours / week</p>
									</div>
									<div class="row center">
									<a href="#modal_job_app${i}" class="modal-trigger btn-large waves-effect waves-light purple lighten-1"> Edit
								        <i class="material-icons right">send</i>
									</a>
									<a href="#!" class="btn-large waves-effect waves-light red lighten-1" id="remove_button_job${i}"> Remove
								        <i class="material-icons right">send</i>
									</a>
									 <p id="confirmation"></p>
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

function display_jobs_by_company() {
    if(window.sessionStorage.getItem('companies') !== undefined && window.sessionStorage.getItem('companies') !== null) {
        let id = window.sessionStorage.getItem('companies');
        let tmp = JSON.parse(id).companies.id;
        return getter(`jobs_companies/${tmp}`).then((response) => {
            return new Promise(async (resolve) => {
                await clearJobs();
                await clearModals();
                for (let i = 0; i < response.length; i++) {
                    document.querySelector("main div.container").innerHTML += returnJob(response[i], i);
                    initApplyForm(response[i].id, response[i].company_id, i, response[i]);
                }
                resolve();
            });
        });
    }
}

async function initApplyForm(job_id, company_id, i, job) {
    await appendModal(i, job);
    await display_child(i, job);
    await display_city(i, job);
    await display_parent(i, job);
    delJobs(job.id, i);
    let element = document.querySelector(`a#send_btn${i}`);

    element.addEventListener('click', async function() {
        let inputCheck = await editJobs(job.id, i);
        if(inputCheck === false)
            document.querySelector(`p#error${i}`).innerText = "Please fill in all the fields";
    });
    return job;
}

function new_job_modal()
{
    let htmlModal = `<div id="modal_job_app" class="modal modal-fixed-footer">
		<div class="modal-content">
			<form class="col s12">
			    <input placeholder="Title" id="title_new_job" type="text" class="validate"/>
			      <label for="title_new_job"> Title </label>
			    <input id="description_new_job" type="text" class="validate"/>
			     <label for="description_new_job"> Description </label>
			     <input  id="salary_new_job" type="text" class="validate"/>
			     <label for="salary_new_job"> Salary </label>
                 <input  id="time_new_job" type="number" class="validate"/>
                  <label for="time_new_job"> Time </label>
                 <div class="input-field">
                        <select id="city_id_n"></select>
                 </div>
                  <label for="city_id_n"> City </label>
               <div class="input-field">
                        <select id="parent_id_n"></select>
                 </div>
                 <label for="parent_id_n"> Parent fields </label>
                 <div class="input-field">
                        <select id="child_id_n"></select>
                 </div>
                  <label for="child_id_s"> Child fields </label>
			</form>
			<a id="send_btn_new" class=" waves-effect btn-flat modal_button">Send
				<i class="material-icons right">send</i>
			</a>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return htmlModal;
}

async function wait_new_job()
{
    document.querySelector("div#modals_div_job").innerHTML += new_job_modal();
}

function display_city_for_new() {
    return getter("cities").then((response) => {
        return new Promise((resolve) => {
            var elements = document.querySelector(`select#city_id_n`);
            for (let i = 0; i < response.length; i++) {
                    elements.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
                    elements.style.display = "block";
            }
            resolve();
        });
    });
}

function display_child_for_new() {
    return getter("child_fields").then((response) => {
        return new Promise((resolve) => {
            var elements = document.querySelector(`select#child_id_n`);
            for (let i = 0; i < response.length; i++) {
                    elements.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
                    elements.style.display = "block";
            }
            resolve();
        });
    });
}

function display_parent_for_new() {
    return getter("parent_fields").then((response) => {
        return new Promise((resolve) => {
            var elements = document.querySelector(`select#parent_id_n`);
            for (let i = 0; i < response.length; i++) {
                    elements.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
                    elements.style.display = "block";
            }
            resolve();
        });
    });
}


async function display_new_job()
{
    await wait_new_job();
    await display_child_for_new();
    await display_city_for_new();
    await display_parent_for_new();
    let element = document.querySelector(`a#send_btn_new`);
    element.addEventListener('click',  function() {
        var Title = document.querySelector(`input#title_new_job`).value;
        var token = JSON.parse(window.sessionStorage.getItem('companies')).token;
        var tmp = window.sessionStorage.getItem('companies')
        var company = JSON.parse(tmp).companies.id;
        var description = document.querySelector(`input#description_new_job`).value;
        var Salary = document.querySelector(`input#salary_new_job`).value;
        var Worktime = document.querySelector(`input#time_new_job`).value;
        var City = document.querySelector(`select#city_id_n`).value;
        var child_fields = document.querySelector(`select#child_id_n`).value;
        var parent_fields = document.querySelector(`select#parent_id_n`).value;
        let req = {
            "title": Title,
            "description": description,
            "salary": Salary,
            "worktime": Worktime,
            "city_id": City,
            "child_fields_id": child_fields,
            "parent_fields_id": parent_fields,
            "company_id": company
        }
        let body = JSON.stringify(req);
        postReqJob(`jobs`, body, token)
            .then((response) => {
                redirect_to_jobs();
            })
            .catch(error => {
                console.log(error)
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

docReady(async () => {
    redirect_to_index_protection();
    nav_working();
    await display_new_job();
    display_jobs_by_company()
        .then(() => {
            initModals();
        });
    logout();
});