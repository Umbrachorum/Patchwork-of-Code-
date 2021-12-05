function returnModal() {
    let htmlModal = `<div id="modal_job_app" class="modal modal-fixed-footer modal_unregistered">
		<div class="modal-content">
			<form class="col s12">
			    <input id="actual_pwd" type="text" class="validate"/>
			      <label for="actual_pwd"> Actual password </label>
			    <input id="new_actual_pwd" type="text" class="validate"/>
			     <label for="new_actual_pwd"> New password </label>
			     <input  id="confirm_new_actual_pwd" type="text" class="validate"/>
			     <label for="confirm_new_actual_pwd"> Password confirmation </label>
			</form>
			<a id="send_btn" class=" waves-effect btn-flat modal_button">Send
				<i class="material-icons right">send</i>
			</a>
		</div>
		<div class="modal-footer">
			<a href="#!" class="modal-close waves-effect waves-green btn-flat">Close</a>
		</div>
	</div>`;
    return htmlModal;
}


function display_user_data() {
    var user = window.sessionStorage.getItem('user');
    document.querySelector("input#first_name").setAttribute('value', JSON.parse(user).user.firstname);
    document.querySelector("input#last_name").setAttribute('value', JSON.parse(user).user.lastname);
    document.querySelector("input#birthdate").setAttribute('value', JSON.parse(user).user.birthdate);
    document.querySelector("input#phone_number").setAttribute('value', JSON.parse(user).user.phone_number);
    document.querySelector("input#email").setAttribute('value', JSON.parse(user).user.email);
}

function editUser() {
    let button_edit_user = document.querySelector("button#validation_edit_user");
    button_edit_user.addEventListener("click", () => {
        var user = window.sessionStorage.getItem('user');
        var token = JSON.parse(user).token;
        var firstname = document.querySelector('input#first_name').value;
        var lastname = document.querySelector('input#last_name').value;
        var birthdate = document.querySelector('input#birthdate').value;
        var phone = document.querySelector('input#phone_number').value;
        var email = document.querySelector('input#email').value;
        var id = JSON.parse(user).user.token_id;
        let req = {
            "firstname": firstname,
            "lastname": lastname,
            "birthdate": birthdate,
            "phone_number": phone,
            "email": email,
        }
        let body = JSON.stringify(req);
        upReq(`users/${id}`, body, token)
            .then((response) => {
                var user_json = {
                    'user': response.user,
                    'token': token,
                }
                window.sessionStorage.setItem('user', JSON.stringify(user_json));
                display_user_data();
                document.querySelector('p#confirmation').innerText = "Profile Updated";
            })
            .catch(error => console.log(error));
    });
}

async function appendModal() {
    if(window.sessionStorage.getItem('user') !== undefined && window.sessionStorage.getItem('user') !== null) {
        document.querySelector("div#modals_div").innerHTML += returnModal();
    }
}

function put_pwd() {
    if(window.sessionStorage.getItem('user') !== undefined && window.sessionStorage.getItem('user') !== null) {
        let id = window.sessionStorage.getItem('user');
        let tmp = JSON.parse(id).user.id;
        let token = JSON.parse(id).token;
        var actual = document.querySelector('input#actual_pwd').value;
        var pwd = document.querySelector('input#new_actual_pwd').value;
        var pwd_confirmation = document.querySelector('input#confirm_new_actual_pwd').value;
        let req = {
            "actual_password": actual,
            "password": pwd,
            "password_confirmation": pwd_confirmation,
        }
        let body = JSON.stringify(req);
        return upReq(`password/${tmp}`, body, token).then((response) => {
            return new Promise(async (resolve) => {
                console.log(response);
                return true;
                resolve();
            });
        });
    }
    return false;
}

async function initApplyForm() {
    await appendModal();
    let element = document.querySelector(`a#send_btn`);
    element.addEventListener('click', async function() {
        let inputCheck = await put_pwd();
        if(inputCheck === false)
            document.querySelector(`p#error`).innerText = "Please fill in all the fields";
    });
}

function initModals() {
    var modal_elems = document.querySelectorAll(".modal");
    var modal_instances = M.Modal.init(modal_elems);
}


function nav_working()
{
    draw_navbar();
    job_button();
    sidenav();
    select_login_logout();
    choose_url_profile();
}

docReady(async () => {

    nav_working();
    editUser();
    display_user_data();
    initApplyForm()
        .then(() => {
            initModals()
        });
    logout();
});

