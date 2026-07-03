var TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {

    const exists = this.cache.has(key);

    if(exists) {
        clearTimeout(this.cache.get(key).timeoutId);
    }

    const timeoutId = setTimeout(() => {
        this.cache.delete(key);
    }, duration);

    this.cache.set(key, {
        value,
        timeoutId
    });

    return exists;
};

TimeLimitedCache.prototype.get = function(key) {

    if(!this.cache.has(key)) {
        return -1;
    }

    return this.cache.get(key).value;
};

TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};