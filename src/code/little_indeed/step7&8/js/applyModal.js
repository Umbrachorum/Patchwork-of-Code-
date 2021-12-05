function returnModal(i) {
	let htmlModal = `<div id="modal${i}" class="modal modal-fixed-footer modal_unregistered">
		<div class="modal-content">
			<form class="col s12">
				<h4>About you</h4>
				<div class="row">
					<div class="input-field col s6">
						<input id="first_name${i}" type="text" class="validate" required>
						<label for="first_name${i}">First Name</label>
					</div>
					<div class="input-field col s6">
						<input id="last_name${i}" type="text" class="validate" required>
						<label for="last_name${i}">Last Name</label>
					</div>
				</div>
				<div class="row">
					<div class="input-field col s12">
					<input id="email${i}" type="email" class="validate" required>
					<label for="email${i}">Email</label>
					</div>
				</div>
				<div class="row">
					<div class="input-field col s6">
						<i class="material-icons prefix">phone</i>
						<input id="phone_number${i}" type="tel" class="validate" required>
						<label for="phone_number${i}">Telephone</label>
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
					<textarea id="textarea${i}" class="materialize-textarea" maxlength="2000" required></textarea>
					<label for="textarea${i}">Your message</label>
					</div>
				</div>
				<p id="error${i}" class="modal_error"></p>
			</form>
			<button id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
				<i class="material-icons right">send</i>
			</button>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
	return htmlModal;
}

function returnRegisteredModal(i) {
	let htmlRegisteredModal = `<div id="modal${i}" class="modal modal-fixed-footer modal_registered">
		<div class="modal-content">
			<form class="col s12">
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
					<textarea id="textarea${i}" class="materialize-textarea" maxlength="2000" required></textarea>
					<label for="textarea${i}">Your message</label>
					</div>
				</div>
				<p id="error${i}" class="modal_error"></p>
			</form>
			<button id="send_btn${i}" class="waves-effect btn-flat modal_button">Send
				<i class="material-icons right">send</i>
			</button>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
	return htmlRegisteredModal;
}

function confirmApplication(i) {
	let element = document.querySelector(`div#modal${i} div.modal-content`);
	let confirmationMessage = `
	<div class="row">
	  <div class="col s12 m7 l7 offset-m2 offset-l2">
		<div class="card">
		  <div class="card-image">
		  <img class="congrats responsive-img" src="https://i.ibb.co/3S67bMz/application-Sent.jpg" alt="application-Sent">
			<h4 class="card-title">CONGRATS !</h4>
		  </div>
		  <div class="card-content">
		  	<h4 class="center-align">Application sent !</h4> 
		  </div>
		</div>
	  </div>
	</div>`;

	element.innerHTML = confirmationMessage;	
}

async function appendModal(i) {

	if(window.sessionStorage.getItem('user') !== undefined && window.sessionStorage.getItem('user') !== null) {
		document.querySelector("div#modals_div").innerHTML += returnRegisteredModal(i);
	} else {
		document.querySelector("div#modals_div").innerHTML += returnModal(i);
	}
}

async function initApplyForm(job_id, company_id, i) {
	await appendModal(i);
	let element = document.querySelector(`button#send_btn${i}`);

	element.addEventListener('click', async function() {
		let inputCheck = await sendApplyForm(job_id, company_id, i);
		if(inputCheck === false)
			document.querySelector(`p#error${i}`).innerText = "Please fill in all the fields";
	});
	return true;
}

async function checkInputs(i) {
	if(window.sessionStorage.getItem('user') !== undefined && window.sessionStorage.getItem('user') !== null) {
		let message = document.querySelector(`textarea#textarea${i}`).value;
		if(message !== "" && message !== undefined && message !== null)
			return true;
		return false;
	} else {
		let message = document.querySelector(`textarea#textarea${i}`).value;
		let firstname = document.querySelector(`input#first_name${i}`).value;
		let lastname = document.querySelector(`input#last_name${i}`).value;
		let email = document.querySelector(`input#email${i}`).value;
		let phone_number = document.querySelector(`input#phone_number${i}`).value;

		if(
			message !== "" && message !== undefined && message !== null &&
			firstname !== "" && firstname !== undefined && firstname !== null &&
			lastname !== "" && lastname !== undefined && lastname !== null &&
			email !== "" && email !== undefined && email !== null &&
			phone_number !== "" && phone_number !== undefined && phone_number !== null
		)
			return true;
		return false;
	}
}

async function errorsHandling(response, i) {
	if(response.OK !== null && response.OK !== undefined) {
		confirmApplication(i);
	} else if (response.errors !== undefined && response.errors.email !== null && response.errors.email !== undefined) {
		document.querySelector(`p#error${i}`).innerText = "The email must be a valid email address";
	} else if (response.errors !== undefined && response.errors.phone_number !== null && response.errors.phone_number !== undefined) {
		document.querySelector(`p#error${i}`).innerText = "The phone number must be a number";
	}
}

async function sendApplyForm(job_id, company_id, i) {

	let inputCheck = await checkInputs(i);
	if(!inputCheck)
		return false;
	if(window.sessionStorage.getItem('user') !== undefined && window.sessionStorage.getItem('user') !== null) {
		let user_object = await JSON.parse(window.sessionStorage.getItem('user'));
		var message = document.querySelector(`textarea#textarea${i}`).value;
		var firstname = user_object.user.firstname;
		var lastname = user_object.user.lastname;
		var email = user_object.user.email;
		var phone_number = user_object.user.phone_number;
	} else {
		var message = document.querySelector(`textarea#textarea${i}`).value;
		var firstname = document.querySelector(`input#first_name${i}`).value;
		var lastname = document.querySelector(`input#last_name${i}`).value;
		var email = document.querySelector(`input#email${i}`).value;
		var phone_number = document.querySelector(`input#phone_number${i}`).value;
	}
	let req = {
		"firstname": firstname,
		"lastname": lastname,
		"email": email,
		"phone_number": phone_number,
		"message": message,
		"cv": null,
		"motivation_letter": null,
		"job_id": job_id,
		"company_id": company_id
	}
	let body = JSON.stringify(req);
	postReq("job_applications", body)
	.then((response) => {
		errorsHandling(response, i);
	})
	.catch(error => console.log(error));
}

function initModals() {
	var modal_elems = document.querySelectorAll(".modal");
	var modal_instances = M.Modal.init(modal_elems);
}