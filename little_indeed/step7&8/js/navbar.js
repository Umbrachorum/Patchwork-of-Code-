function pimp_my_navbar() {
    return `
                        <a href="index.html" class="brand-logo jobtitle">JoBoard</a>
                        <a href="#" data-target="slide-out" class="sidenav-trigger"><i class="material-icons">menu</i></a>
                        <ul class="right hide-on-med-and-down">
                            <li id="profile_user"><a href="../view/user.html"><i class="material-icons left">account_circle</i>profile</a></li>
                            <li id="job_panel"><a href="../view/jobs.html"><i class="material-icons left">account_circle</i>jobs</a></li>
                            <li id="profile_company"><a href="../view/company.html"><i class="material-icons left">account_circle</i>profile</a></li>
                            <li id="logout"><a><i class="material-icons left">close</i>Logout</a></li>
                            <li id="login"><a href="../view/login.html"><i class="material-icons left">account_circle</i>Login</a></li>
                        </ul>
                        <ul id="slide-out" class="sidenav">
							<li id="profile_side"><a href="index.html">Index</a></li>
                            <li id="profile_side"><a href="user.html">Profile</a></li>
                            <li id="logout_side"><a href="#">logout</a></li>
                            <li id="login_side"><a href="login.html">login</a></liid>
                        </ul>
                  `;
}

function choose_url_profile() {
    let button_profile_user = document.querySelector("li#profile_user");
    let button_profile_company = document.querySelector("li#profile_company");
    if ((window.sessionStorage.getItem('user') !== null && window.sessionStorage.getItem('user') !== undefined) || (window.sessionStorage.getItem('companies') !== null && window.sessionStorage.getItem('companies') !== undefined)) {
        if ((window.sessionStorage.getItem('companies') !== null && window.sessionStorage.getItem('companies') !== undefined)) {
            button_profile_user.style.display = 'none';
            button_profile_company.style.display = 'block';
        }
        if ((window.sessionStorage.getItem('user') !== null && window.sessionStorage.getItem('user') !== undefined)) {
            button_profile_user.style.display = 'block';
            button_profile_company.style.display = 'none';
        }
    }
    else  {
        button_profile_user.style.display = 'none';
        button_profile_company.style.display = 'none';
    }
}

function job_button() {
    let button_job = document.querySelector("li#job_panel");
    if ((window.sessionStorage.getItem('companies') !== null && window.sessionStorage.getItem('companies') !== undefined)) {
        button_job.style.display = 'block';
    } else {
        button_job.style.display = 'none';
    }
}



function draw_navbar() {
        document.getElementById('pimp_my_navbar').innerHTML +=  pimp_my_navbar();
}

function logout() {
    if(window.sessionStorage.getItem('user') !== null && window.sessionStorage.getItem('user') !== undefined)
    {
        let button_logout = document.querySelector("li#logout");
        button_logout.addEventListener("click", () => {
            var user = window.sessionStorage.getItem('user');
            var token = JSON.parse(user).token;
            upReqLog("users/logout", token)
                .then((response) => {
                    //window.sessionStorage.removeItem('user');
                    window.sessionStorage.clear();
                    redirect_to_index();
                    select_login_logout();
                })
                .catch(error => console.log(error));
        });
    }
    if(window.sessionStorage.getItem('companies') !== null && window.sessionStorage.getItem('companies') !== undefined)
    {
        let button_logout = document.querySelector("li#logout");
        button_logout.addEventListener("click", () => {
            var user = window.sessionStorage.getItem('companies');
            var token = JSON.parse(user).token;
            upReqLog("companies/logout", token)
                .then((response) => {
                    window.sessionStorage.clear();
                    redirect_to_index();
                    select_login_logout();
                })
                .catch(error => console.log(error));
        });
    }
}

function sidenav() {
    var sidenav_elems = document.querySelectorAll('.sidenav');
    var sidenav_instances = M.Sidenav.init(sidenav_elems, {preventScrolling: true});
}

function docReady(fn) {
    // see if DOM is already available
    if (document.readyState === "complete" || document.readyState === "interactive") {
        // call on next available tick
        setTimeout(fn, 1);
    } else {
        document.addEventListener("DOMContentLoaded", fn);
    }
}

function select_login_logout() {
    let button_login = document.querySelector("li#login");
    let button_logout = document.querySelector("li#logout");
    if((window.sessionStorage.getItem('user') !== null && window.sessionStorage.getItem('user') !== undefined) || (window.sessionStorage.getItem('companies') !== null && window.sessionStorage.getItem('companies') !== undefined))
    {
        button_logout.style.display = 'block';
        button_login.style.display = 'none';
    }
    else {
        button_logout.style.display = 'none';
        button_login.style.display = 'block';
    }
}