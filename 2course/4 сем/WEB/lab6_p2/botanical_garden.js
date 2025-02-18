class TLocalStorage
{
    constructor() { this.storage = window.localStorage; }

    Reset() { this.storage.clear(); }

    AddValue(key, value) { this.storage.setItem(key, value); }

    GetValue(key)
    {
        if (this.storage.getItem(key) !== null)
            return this.storage.getItem(key);
        else
            return undefined;
    }

    DeleteValue(key)
    {
        if (this.storage.getItem(key) !== null)
            this.storage.removeItem(key);
    }

    GetKeys() { return Object.keys(this.storage); }
}
