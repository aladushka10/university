var MenuA = [
    {name:'Цветы',submenu:
            [
                {name: 'Пионы', submenu:
                        [
                            {name:'Пион уклоняющийся', url: 'https://ru.wikipedia.org/wiki/Пион_уклоняющийся'},
                            {name:'Пион крымский', url: 'https://ru.wikipedia.org/wiki/Пион_крымский'}
                        ]
                },
                {name:'Орхидеи', url: 'https://ru.wikipedia.org/wiki/Орхидные'},
                {name:'Лилии', submenu:
                        [
                            {name:'Азиатские лилии', url: 'https://www.ogorod.ru/ru/outdoor/bulbs/10323/9-luchshih-sortov-aziatskih-lilij.htm'},
                            {name:'Касатики', url: 'https://ru.wikipedia.org/wiki/Lilium'}
                        ]
                }
            ]
    },

    {name: 'Деревья', url: "https://ru.wikipedia.org/wiki/Дерево"},

    {name:'Травы', submenu:
            [
                {name:'Мята', url: 'https://ru.wikipedia.org/wiki/Мята'},
                {name:'Лаванда', url: 'https://ru.wikipedia.org/wiki/Лаванда'},
                {name:'Ромашка', url: 'https://ru.wikipedia.org/wiki/Ромашка'}
            ]
    }
];

function ShowMenu(MenuItemsA, ParentElem) {
    var menu = document.createElement('div'); //подменю
    menu.classList.add('submenu');

    MenuItemsA.forEach(function(item) {
        var div = document.createElement('div'); //для элемента подменю
        var a = document.createElement('a'); //текст элемента
        a.textContent = item.name;
        if (item.url) {
            a.setAttribute('href', item.url);
        } else if (item.submenu) {
            a.style.cursor = 'pointer';
            a.onclick = function() {                 //обработчик события клика на ссылку
                ShowMenu(item.submenu, div);
            };
        }
        div.appendChild(a);          //добавляем элемент ссылки в элемент списка <div>
        menu.appendChild(div);
    });

    ParentElem.appendChild(menu);   //добавляем подменю к родительскому элементу меню
}

document.addEventListener("DOMContentLoaded", function() {
// основное меню
    var mainMenu = document.getElementById('mainMenu');
    MenuA.forEach(function (item) {
        var div = document.createElement('div');
        var a = document.createElement('a');
        a.textContent = item.name;
        if (item.url) {
            a.setAttribute('href', item.url);
        } else if (item.submenu) {
            a.style.cursor = 'pointer';
            a.onclick = function () {
                ShowMenu(item.submenu, div);
            };
        }
        div.appendChild(a);
        mainMenu.appendChild(div);
    });
});