class EventEmitter {

    constructor() {
        this.events = {};
    }

    subscribe(eventName, callback) {

        if(!this.events[eventName]) {
            this.events[eventName] = [];
        }

        this.events[eventName].push(callback);

        return {
            unsubscribe: () => {

                this.events[eventName] =
                    this.events[eventName]
                        .filter(cb => cb !== callback);

            }
        };
    }

    emit(eventName, args = []) {

        if(!this.events[eventName]) {
            return [];
        }

        let result = [];

        for(let cb of this.events[eventName]) {
            result.push(cb(...args));
        }

        return result;
    }
}