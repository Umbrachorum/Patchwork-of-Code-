function initTabs() {
    const options = {
        duration: 300,
        onShow: null,
        swipeable: false,
        responsiveThreshold: Infinity
    };
    const tabsContainer = document.querySelectorAll(".tabs");
    M.Tabs.init(tabsContainer, options);
}

function showDiv() {
    let button_login = document.querySelectorAll("a.switch_login");
    let button_signup = document.querySelectorAll("a#switch_signup");
    button_login.forEach(element => {
        element.addEventListener("click", () => {
            document.querySelectorAll(".signin_tab").forEach(elem => {
                elem.style.display = "block";
            })
            document.querySelectorAll(".signup_tabs").forEach(elem => {
                elem.style.display = "none";
            });
            document.querySelector("#signin_1").style.display = "block";
        })
    });
    button_signup.forEach(element => {
        element.addEventListener("click", () => {
            document.querySelectorAll(".signin_tab").forEach(elem => {
                elem.style.display = "none";
            })
            document.querySelectorAll(".signup_tabs").forEach(elem => {
                elem.style.display = "block";
            });
            document.querySelector("#signin_1").style.display = "none";
            document.querySelector("#signin_2").style.display = "none";
        });
    });
}

function display_city() {
    return getter("cities").then((response) => {
        return new Promise((resolve) => {
            var elements = document.querySelectorAll("option");
            for (let i = 0; i < elements.length; i++) {
                elements[i].innerText = response[i].name;
                elements[i].value = response[i].id;
            }
            resolve();
        });
    });
}

function drop_city() {
    var elems = document.querySelector('select');
    var instances = M.FormSelect.init(elems);
}

function sendLogin() {
    let button_login_company = document.querySelector("button#validation_log_in_company");
    let button_login_user = document.querySelector("button#validation_log_in_user");
    button_login_user.addEventListener("click", () => {
        var email = document.querySelector('input#email_sign_in_user').value;
        var password = document.querySelector('input#password_sign_in_user').value;
        let req = {
            "email": email,
            "password": password
        }
        let body = JSON.stringify(req);
        postReq("users/login", body)
            .then((response) => {
              let data = JSON.parse(JSON.stringify(response));
                if(data.hasOwnProperty('message')) {
                    window.alert(data.message);
                }
                else {
                    window.sessionStorage.setItem('user', JSON.stringify(response));
                    redirect_to_index();
                }
            })
            .catch(error => console.log(error));
    });
    button_login_company.addEventListener("click", () => {
        var email = document.querySelector('input#email_sign_in_company').value;
        var password = document.querySelector('input#password_sign_in_company').value;
        let req = {
            "email": email,
            "password": password
        }
        let body = JSON.stringify(req);
        postReq("companies/login", body)
            .then((response) => {
                let data = JSON.parse(JSON.stringify(response));
                if(data.hasOwnProperty('message')) {
                    window.alert(data.message);
                }
                else {
                    window.sessionStorage.setItem('companies', JSON.stringify(response));
                    redirect_to_index();
                }
            })
            .catch(error => console.log(error));
    });
}

function redirect_to_index(){
    document.location.href="../view/index.html";
}

function redirect_to_login(){
    document.location.href="../view/login.html";
}

function sendRegister() {
    let button_register_company = document.querySelector("button#button_register_company");
    let button_register_user = document.querySelector("button#button_register_user");
    button_register_user.addEventListener("click", () => {
        var firstname= document.querySelector('input#first_name_register_user').value;
        var lastname= document.querySelector('input#last_name_register_user').value;
        var birthdate= document.querySelector('input#birthdate_register_user').value;
        var phone= document.querySelector('input#tel_register_user').value;
        var email = document.querySelector('input#email_register_user').value;
        var password = document.querySelector('input#password_register_user').value;
        var confirm_password = document.querySelector('input#password_confirm_register_user').value;
        let req = {
            "firstname": firstname,
            "lastname": lastname,
            "birthdate": birthdate,
            "phone_number": phone,
            "email": email,
            "password": password,
            "password_confirmation": confirm_password
        }
        let body = JSON.stringify(req);
        postReq("users/register", body)
            .then((response) => {
                let data = JSON.parse(JSON.stringify(response));
                if(data.hasOwnProperty('message')) {
                    window.alert(data.message);
                }
                else {
                    window.sessionStorage.setItem('user', JSON.stringify(response));
                    redirect_to_index();
                }
            })
            .catch(error => console.log(error));
    });
    button_register_company.addEventListener("click", () => {
        var name= document.querySelector('input#name_register_company').value;
        var description= document.querySelector('input#description_register_company').value;
        var city= document.querySelector('select#city_id').value;
        var email = document.querySelector('input#email_register_company').value;
        var password = document.querySelector('input#password_register_company').value;
        var confirm_password = document.querySelector('input#password_confirm_register_company').value;
        let req = {
            "name": name,
            "description": description,
            "city": city,
            "email": email,
            "password": password,
            "password_confirmation": confirm_password
        }
        let body = JSON.stringify(req);
        postReq("companies/register", body)
            .then((response) => {
                let data = JSON.parse(JSON.stringify(response));
                if(data.hasOwnProperty('message')) {
                    window.alert(data.message);

                }
                else {
                    window.sessionStorage.setItem('companies', JSON.stringify(response));
                    redirect_to_index();
                }
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
}

docReady(() => {
    nav_working();
    initTabs();
    sendLogin();
    display_city().then(function () {
        drop_city();
        }
    );
    sendRegister();
    redirect_to_index_online();
    showDiv();
    logout();
});

