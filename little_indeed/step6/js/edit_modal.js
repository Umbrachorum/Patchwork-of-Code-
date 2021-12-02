function returnModal(i, job) {
    let htmlModal = `<div id="modal_job_app${i}" class="modal modal-fixed-footer modal_unregistered">
		<div class="modal-content">
			<form class="col s12">
			    <input placeholder="Title" id="title_edit_job${i}" type="text" class="validate" value="${job.title}"/>
			      <label for="title_edit_job"> Title </label>
			    <input placeholder="Description" id="description_edit_job${i}" type="text" class="validate" value="${job.description}"/>
			     <label for="description_edit_job"> Description </label>
			     <input placeholder="Salary" id="salary_edit_job${i}" type="text" class="validate" value="${job.salary}"/>
			     <label for="salary_edit_job"> Salary </label>
                 <input placeholder="Worktime" id="time_edit_job${i}" type="text" class="validate" value="${job.worktime}"/>
                  <label for="time_edit_job"> Time </label>
                 <div class="input-field">
                        <select id="city_id${i}">
                        </select>
                 </div>
                  <label for="city_id"> City </label>
                 <div class="input-field">
                    <select id="parent_id${i}" name="parent_id${i}"></select>
                 </div>
                 <label for="parent_id"> Parent fields </label>
                 <div class="input-field">
                        <select id="child_id${i}">
                        </select>
                 </div>
                  <label for="child_id"> Child fields </label>
			</form>
			<a id="send_btn${i}" class=" waves-effect btn-flat modal_button">Send
				<i class="material-icons right">send</i>
			</a>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return htmlModal;
}

function display_city(index, job) {
    let arr = [];
    return getter("cities").then((response) => {
        return new Promise((resolve) => {
            var elements = document.querySelector(`select#city_id${index}`);
            for (let i = 0; i < response.length; i++) {
                if(job.city_name === response[i].name) {
                    elements.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
                    elements.style.display = "block";
                }
                else
                    arr.push(`<option value="${response[i].id}">${response[i].name}</option>`);
            }
            for (let x = 0; x < arr.length; x++) {
                elements.innerHTML += arr[x];
                elements.style.display = "block";
            }
            resolve();
        });
    });
}

function display_child(index, job) {
    let arr = [];
    return getter("child_fields").then((response) => {
        return new Promise((resolve) => {
            var elements = document.querySelector(`select#child_id${index}`);
            for (let i = 0; i < response.length; i++) {
                if(job.child_field_name === response[i].name) {
                    elements.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
                    elements.style.display = "block";
                }
                else
                    arr.push(`<option value="${response[i].id}">${response[i].name}</option>`);
            }
            for (let x = 0; x < arr.length; x++) {
                elements.innerHTML += arr[x];
                elements.style.display = "block";
            }
            resolve();
        });
    });
}

function display_parent(index, job) {
    let arr = [];
    return getter("parent_fields").then((response) => {
        return new Promise((resolve) => {
            var elements = document.querySelector(`select#parent_id${index}`);
            for (let i = 0; i < response.length; i++) {
                if(job.parent_field_name === response[i].name) {
                    elements.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
                    elements.style.display = "block";
                }
                else
                    arr.push(`<option value="${response[i].id}">${response[i].name}</option>`);
            }
            for (let x = 0; x < arr.length; x++) {
                elements.innerHTML += arr[x];
                elements.style.display = "block";
            }
            resolve();
        });
    });
}


async function appendModal(i, job) {
    if(window.sessionStorage.getItem('companies') !== undefined && window.sessionStorage.getItem('companies') !== null) {
        document.querySelector("div#modals_div").innerHTML += returnModal(i, job);
    }
}

function initModals() {
    var modal_elems = document.querySelectorAll(".modal");
    var modal_instances = M.Modal.init(modal_elems);
}

async function editJobs(id, i) {
        var Title = document.querySelector(`input#title_edit_job${i}`).value;
        var token = JSON.parse(window.sessionStorage.getItem('companies')).token;
        var description = document.querySelector(`input#description_edit_job${i}`).value;
        var Salary = document.querySelector(`input#salary_edit_job${i}`).value;
        var Worktime = document.querySelector(`input#time_edit_job${i}`).value;
        var City = document.querySelector(`select#city_id${i}`).value;
        var child_fields = document.querySelector(`select#child_id${i}`).value;
        var parent_fields = document.querySelector(`select#parent_id${i}`).value;
        let req = {
            "title": Title,
            "description": description,
            "salary": Salary,
            "worktime": Worktime,
            "city_id": City,
            "child_fields_id": child_fields,
            "parent_fields_id": parent_fields,
            "company_id": null
        }
        let body = JSON.stringify(req);
        upReq(`jobs/${id}`, body, token)
            .then((response) => {
                redirect_to_jobs();
                return true;
            })
            .catch(error => {
                console.log(error);
                return false;
            });
}

function delJobs(id, i) {
    let del_button = document.querySelector(`a#remove_button_job${i}`);
    var token = JSON.parse(window.sessionStorage.getItem('companies')).token;
    del_button.addEventListener("click", () => {
        delReq(`jobs/${id}`, token)
            .then((response) => {
                redirect_to_jobs();
            })
            .catch(error => console.log(error));
    });
}