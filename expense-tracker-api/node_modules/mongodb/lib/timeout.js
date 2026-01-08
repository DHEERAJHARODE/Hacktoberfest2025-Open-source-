"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Timeout = exports.TimeoutError = void 0;
const timers_1 = require("timers");
const error_1 = require("./error");
const utils_1 = require("./utils");
/** @internal */
class TimeoutError extends Error {
    get name() {
        return 'TimeoutError';
    }
    constructor(message, options) {
        super(message, options);
    }
    static is(error) {
        return (error != null && typeof error === 'object' && 'name' in error && error.name === 'TimeoutError');
    }
}
exports.TimeoutError = TimeoutError;
/**
 * @internal
 * This class is an abstraction over timeouts
 * The Timeout class can only be in the pending or rejected states. It is guaranteed not to resolve
 * if interacted with exclusively through its public API
 * */
class Timeout extends Promise {
    get [Symbol.toStringTag]() {
        return 'MongoDBTimeout';
    }
    /** Create a new timeout that expires in `duration` ms */
    constructor(executor = () => null, duration, unref = false) {
        let reject;
        if (duration < 0) {
            throw new error_1.MongoInvalidArgumentError('Cannot create a Timeout with a negative duration');
        }
        super((_, promiseReject) => {
            reject = promiseReject;
            executor(utils_1.noop, promiseReject);
        });
        this.ended = null;
        this.timedOut = false;
        this.duration = duration;
        this.start = Math.trunc(performance.now());
        if (this.duration > 0) {
            this.id = (0, timers_1.setTimeout)(() => {
                this.ended = Math.trunc(performance.now());
                this.timedOut = true;
                reject(new TimeoutError(`Expired after ${duration}ms`));
            }, this.duration);
            if (typeof this.id.unref === 'function' && unref) {
                // Ensure we do not keep the Node.js event loop running
                this.id.unref();
            }
        }
    }
    /**
     * Clears the underlying timeout. This method is idempotent
     */
    clear() {
        (0, timers_1.clearTimeout)(this.id);
        this.id = undefined;
    }
    static expires(durationMS, unref) {
        return new Timeout(undefined, durationMS, unref);
    }
    static is(timeout) {
        return (typeof timeout === 'object' &&
            timeout != null &&
            Symbol.toStringTag in timeout &&
            timeout[Symbol.toStringTag] === 'MongoDBTimeout' &&
            'then' in timeout &&
            typeof timeout.then === 'function');
    }
}
exports.Timeout = Timeout;
//# sourceMappingURL=timeout.js.map