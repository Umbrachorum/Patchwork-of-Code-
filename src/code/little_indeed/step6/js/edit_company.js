function display_city_for_company() {
    let arr = [];
    return getter("cities").then((response) => {
        return new Promise((resolve) => {
            var elements = document.querySelector(`select#city_id`);
			let id = window.sessionStorage.getItem('companies');
			let tmp = JSON.parse(id).companies.city_id;
            for (let i = 0; i < response.length; i++) {
				console.log(JSON.parse(id).companies.city_id);
				console.log(response[i].id);
                if(tmp === response[i].id) {
					console.log('prout');
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
			arr = [];
			console.log(arr);
            resolve();
        });
    });
}

async function display_company_data() {
    var company = window.sessionStorage.getItem('companies');
	await display_city_for_company(); 
    document.querySelector("input#name").setAttribute('value', JSON.parse(company).companies.name);
    document.querySelector("input#description").setAttribute('value', JSON.parse(company).companies.description);
    document.querySelector("input#email").setAttribute('value', JSON.parse(company).companies.email);
}

function redirect_to_company_protection(){
    if(window.sessionStorage.getItem('companies') === null || window.sessionStorage.getItem('companies') === undefined) {
        document.location.href="../view/company.html";
    }
}

async function editCompany() {
    let button_edit_company = document.querySelector("button#validation_edit_company");
    button_edit_company.addEventListener("click", () => {
        var company = window.sessionStorage.getItem('companies');
        var token = JSON.parse(company).token;
        var name = document.querySelector('input#name').value;
        var description = document.querySelector('input#description').value;
        var city = document.querySelector('select#city_id').value;
        var email = document.querySelector('input#email').value;
        var id = JSON.parse(company).companies.token_id;
        let req = {
            "name": name,
            "description": description,
            "city_id": city,
            "email": email,
        }
        let body = JSON.stringify(req);
        upReq(`companies/${id}`, body, token)
            .then((response) => {
                var company_json = {
                    'companies': response.companies,
                    'token': token,
                }
                window.sessionStorage.setItem('companies', JSON.stringify(company_json));
				window.alert('test');
				redirect_to_company_protection();
                /*display_company_data();
                document.querySelector('p#confirmation').innerText = "Profile Updated";*/
            })
            .catch(error => console.log(error));
    });
}

function decline (id){
	let myButton = document.querySelector(`a#decline_app`);
	var token = JSON.parse(window.sessionStorage.getItem('companies')).token;
	myButton.addEventListener("click", () => {
		delReq(`job_application_${id}`, token).then((reponse) => {
			redirect_to_company_protection();
		})
		.catch(error => console.log(error));
	});
}

function nav_working()
{
    draw_navbar();
    job_button();
    sidenav();
    select_login_logout();
    choose_url_profile();
    job_button();
}

docReady(() => {

    nav_working();
    editCompany();
    display_company_data();
    logout();
});

