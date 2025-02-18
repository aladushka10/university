import { fromEvent } from "rxjs";
import {ajax} from "rxjs/ajax";
import {switchMap, map} from "rxjs/operators";

const showDataButton = document.getElementById('showDataButton');
const deleteButton = document.getElementById('deleteButton');
const dataList = document.getElementById('dataList');

// Обработка щелчка по кнопке "Показать данные"
fromEvent(showDataButton, 'click')
  .pipe(
    switchMap(() => ajax.getJSON('botanical_info.json')),
    map(data => data.flowers)
  )
  .subscribe(flowers => {
    dataList.innerHTML = ''; // Очищаем список перед отображением новых данных
    flowers.forEach(item => {
      const listItem = document.createElement('li');
      listItem.textContent = `Название: ${item.name}, Описание: ${item.description}`;
      dataList.appendChild(listItem);
    });
    window.location.href = 'http://localhost:3000/download/botanical_info.json';
  });

// Обработка щелчка по кнопке "Удалить"
fromEvent(deleteButton, 'click')
  .subscribe(() => {
    const lastItem = dataList.lastElementChild;
    if (lastItem) {
      dataList.removeChild(lastItem);
    }
  });
