async function appendAddButton() {
	let active_panel = window.sessionStorage.getItem('active_table');
	let button_div = document.querySelector('div.container.admin_container div#add_btn');
	let modal_id = "";
	switch(active_panel) {
		case "job_panel":
			modal_id = "#modal_job";
			break;
		case "user_panel":
			modal_id = "#modal_user";
			break;
		case "company_panel":
			modal_id = "#modal_company";
			break;
		case "parents_fields_panel":
			modal_id = "#modal_parent_field";
			break;
		case "childs_fields_panel":
			modal_id = "#modal_child_field";
			break;
		case "cities_panel":
			modal_id = "#modal_city";
			break;
	}
	button_div.innerHTML = `<a href="${modal_id}" class="waves-effect waves-light btn modal-trigger"><i class="material-icons right">add</i>ADD</a>`;
	return modal_id;
}

async function appendAddCities(index, response) {
	let element = document.querySelector(`select#city_id${index}`);
	for(let i = 0; i < response.length; i++) {
		element.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
	}
	element.style.display = "block";
}
async function appendAddParentFields(index, response) {
	let element = document.querySelector(`select#parent_id${index}`);
	for(let i = 0; i < response.length; i++) {
		element.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
	}
	element.style.display = "block"; 
}
async function appendAddChildFields(index, response) {
	let element = document.querySelector(`select#child_id${index}`);
	for(let i = 0; i < response.length; i++) {
		element.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
	}
	element.style.display = "block";
}
async function appendAddCompanies(index, response) {
	let element = document.querySelector(`select#company_id${index}`);
	for(let i = 0; i < response.length; i++) {
		element.innerHTML += `<option value="${response[i].id}">${response[i].name}</option>`;
	}
	element.style.display = "block";
}

async function initAddButton(cities, parent_fields, child_fields, companies) {
	let modal_id = await appendAddButton();
	let index = "";
	switch(modal_id) {
		case "#modal_job":
			index = "_job";
			await appendAddCities(index, cities);
			await appendAddParentFields(index, parent_fields);
			await appendAddChildFields(index, child_fields);
			await appendAddCompanies(index, companies);
			break;
		case "#modal_company":
			index = "_company";
			await appendAddCities(index, cities);
			break;
		case "#modal_child_field":
			index = "_child_field";
			await appendAddParentFields(index, parent_fields);
			break;
	}
	document.querySelector(`div${modal_id} button.add_send_btn`).addEventListener('click', async () => {
		sendAdminAddForm(modal_id, cities, parent_fields, child_fields, companies);
	});
}

async function checkInputsAddForm(modal_id) {
	let collection = document.querySelector(`div${modal_id} form`);
	for (let input of collection) {
		if(input.value === null || input.value === undefined || input.value === "") {
			return false;
		} 
	}
	return true;
}

async function errorsHandlingAddForm(response, modal_id) {
	let i = modal_id.slice(6);
	if((response.OK !== null && response.OK !== undefined) || (response.user !== null && response.user !== undefined)) {
		document.querySelector(`p#error${i}`).innerText = "";
		confirmEdit(i);
	} else if (response.errors !== undefined && response.errors.email !== null && response.errors.email !== undefined) {
		document.querySelector(`div${modal_id} p.modal_updated`).innerText = "";
		document.querySelector(`p#error${i}`).innerText = "The email must be a valid email address";
	} else if (response.errors !== undefined && response.errors.phone_number !== null && response.errors.phone_number !== undefined) {
		document.querySelector(`div${modal_id} p.modal_updated`).innerText = "";
		document.querySelector(`p#error${i}`).innerText = "The phone number must be a number";
	}
}

async function sendAdminAddForm(modal_id, cities, parent_fields, child_fields, companies) {
	let inputCheck = await checkInputsAddForm(modal_id);
	if(inputCheck === false)
		return false;
	let collection = document.querySelector(`div${modal_id} form`);
	var request = {};
	for(let input of collection) {
		if(input.localName === 'textarea') {
			request[`${input.name}`] = input.value;
		} else {
			request[`${input.name}`] = input.value;
		}
	}
	let body = JSON.stringify(request);
	let path = "";
	switch(modal_id) {
		case "#modal_job":
			path = `jobs`;
			break;
		case "#modal_user":
			path = `users/register`;
			break;
		case "#modal_company":
			path = `companies/register`;
			break;
		case "#modal_parent_field":
			path = `parent_fields`;
			break;
		case "#modal_child_field":
			path = `child_fields`;
			break;
		case "#modal_city":
			path = `cities`;
			break;
	}
	let token = JSON.parse(window.sessionStorage.getItem('user')).token;
	postReqWithToken(path, body, token)
	.then((response) => {
		console.log(response);
		errorsHandlingAddForm(response, modal_id);
		displayTable(window.sessionStorage.getItem('active_table'), cities, parent_fields, child_fields, companies)
		.then(async () => {
			await initAddButton(cities, parent_fields, child_fields, companies);
			initModals();
		});
	})
	.catch(error => console.log(error));
}