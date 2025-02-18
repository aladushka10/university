class THashStorage {
    constructor() { this.storage = {};}

    Reset() { this.storage = {};}

    AddValue(key, value) { this.storage[key] = value;}

    GetValue(key)
    {
        if (this.storage.hasOwnProperty(key))
        {
            return this.storage[key];
        }
        else
        {
            return undefined;
        }
    }

    DeleteValue(key)
    {
        if (this.storage.hasOwnProperty(key))
        {
            delete this.storage[key];
        }
    }

    GetKeys() { return Object.keys(this.storage);}
}



















/*// пустой хэш
var plantInfoHash = {};

function AddValue(key, value) {
    plantInfoHash[key] = value;
}

function DeleteValue(key) {
    if (plantInfoHash.hasOwnProperty(key)) {
        delete plantInfoHash[key];
    }
}

function GetValueInfo(key) {
    if (plantInfoHash.hasOwnProperty(key)) {
        return plantInfoHash[key];
    } else {
        return "нет информации";
    }
}

function ListValues() {
    let resultString = "";
    for (let key in plantInfoHash) {
        resultString += key + ' – ' + plantInfoHash[key] + '\n';
    }

    return resultString.trim();
}*/