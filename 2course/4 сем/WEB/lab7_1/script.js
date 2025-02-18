"use strict";
window.onhashchange = switchToStateFromURLHash;
var SPAState = {}; //текущее состояние приложения

function switchToStateFromURLHash() {
    var URLHash = window.location.hash;        //получает текущий хэш URL страницы
    var stateStr = URLHash.substr(1);

    if (stateStr !== "")
        SPAState = { pagename: stateStr };
    else
        SPAState = { pagename: 'Main' };

    console.log('Новое состояние приложения:');
    console.log(SPAState);

    var pageHTML = "";
    switch (SPAState.pagename) {
        case 'Main':
            pageHTML += "<h3>Welcom в яркое царство растений</h3>" +
                "<p>Мы рады приветствовать вас в нашем уютном Ботаническом саду, где вы можете насладиться красотой природы и узнать много интересного о растениях.</p>";
            pageHTML += "<p>Выберите интересующую вас информацию!</p>";
            break;
        case 'Info':
            pageHTML += "<h3>Информация о растениях в Ботаническом саду</h3>";
            pageHTML += "<p>Добро пожаловать на страницу информации о растениях! Здесь вы найдете полезные советы по уходу за растениями, такими как:</p>" +
                "<ul>" +
                "<li>Роза: поливать ежедневно и обеспечить солнечный свет.</li>" +
                "<li>Орхидея: держать в тени и часто опрыскивать.</li>" +
                "<li>Суккулент: умеренно поливать и обеспечить много солнечного света.</li>" +
                "</ul>";
            break;
    }
    document.getElementById('botanicalInfo').innerHTML = pageHTML;
}

function switchToState(newState) {  //изменяет состояние приложения
    var stateStr = newState.pagename;       //устанавливаем новый хэш URL страницы равным значению stateStr
    location.hash = stateStr;
}

function switchToMainPage() { switchToState({ pagename: 'Main' }); }

function switchToInfoPage() { switchToState({ pagename: 'Info' }); }

document.addEventListener("DOMContentLoaded", function(event) { switchToStateFromURLHash(); });
