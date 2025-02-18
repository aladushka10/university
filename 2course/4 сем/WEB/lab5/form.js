var BotanicalGardenForm = [
    { label: 'Имя:', elemtype: 'text', name: 'name', placeholder: 'Введите ваше имя', required: true },
    { label: 'Электронная почта:', elemtype: 'text', name: 'mail', placeholder: 'Введите вашу почту' },
    { label: 'Выберите растение:', elemtype: 'select', name: 'plant', options: ['Роза', 'Лилия', 'Орхидея', 'Тюльпан'], required: true },
    { label: 'Комментарии:', elemtype: 'textarea', name: 'comments', placeholder: 'Введите ваш комментарий', rows: 4, cols: 50 },
    { label: 'Отослать:', elemtype: 'button', type: 'button', value: 'Отправить' }
];

function createFormElements(formName, formData) {
    var form = document.getElementById(formName);
    formData.forEach(function(item) {
        var label = document.createElement('label');
        label.textContent = item.label;
        form.appendChild(label);

        switch (item.elemtype) {
            case 'text':
                var input = document.createElement('input');
                input.type = 'text';
                input.name = item.name;
                input.placeholder = item.placeholder;
                form.appendChild(input);
                var errLabel = document.createElement('label');
                errLabel.textContent = "";
                errLabel.id = input.name + 'Err';
                form.appendChild(errLabel);
                break;
            case 'textarea':
                var textarea = document.createElement('textarea');
                textarea.name = item.name;
                textarea.placeholder = item.placeholder;
                textarea.rows = item.rows;
                textarea.cols = item.cols;
                form.appendChild(textarea);
                break;
            case 'select':
                var select = document.createElement('select');
                select.name = item.name;
                item.options.forEach(function(option) {
                    var optionElement = document.createElement('option');
                    optionElement.value = option;
                    optionElement.textContent = option;
                    select.appendChild(optionElement);
                });
                form.appendChild(select);
                break;
            case 'button':
                var button = document.createElement('button');
                button.type = item.type;
                button.textContent = item.value;
                form.appendChild(button);
                break;
            default:
                console.error('Неизвестный тип элемента: ' + item.elemtype);
                break;
        }

        form.appendChild(document.createElement('br'));
    });
}

function isValidEmail(email) {
    var emailRegex = /^[a-zA-Z0-9._-]+@[a-zA-Z]+\.[a-zA-Z]+$/;
    return emailRegex.test(email);
}

function isValidName(name)
{
    var nameRegex = /^[а-яА-Я]+$/;
    return nameRegex.test(name);
}

function validateField(input) {
    var errLabel = document.getElementById(input.name + 'Err');
    if (input.name === "mail")
    {
        if (isValidEmail(input.value))
            errLabel.textContent = "";
        else
            errLabel.textContent = "Некорректный email!";
    } else
    {
        if (input.name === "name")
        {
            if (isValidName(input.value))
                errLabel.textContent = "";
            else
                errLabel.textContent = "Имя должно состоять только из букв русского алфавита.";
        }
    }
}

function validateAllFields() {
    document.querySelectorAll('input[type="text"]').forEach(function(input) {
            validateField(input);
    });
}

document.addEventListener("DOMContentLoaded", function(event) {
    createFormElements("botanicalForm", BotanicalGardenForm);
    document.querySelectorAll('input[type="text"]').forEach(function(input) {
        input.addEventListener('input', function() {
            validateField(input);
        });
    });

    document.querySelectorAll('button').forEach(function(button) {
        if (button.textContent === "Отправить") {
            button.addEventListener('click', validateAllFields);
        }
    });
});
