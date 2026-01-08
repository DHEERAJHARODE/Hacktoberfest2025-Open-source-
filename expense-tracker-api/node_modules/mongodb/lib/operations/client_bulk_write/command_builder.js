"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.buildReplaceOneOperation = exports.buildUpdateManyOperation = exports.buildUpdateOneOperation = exports.buildDeleteManyOperation = exports.buildDeleteOneOperation = exports.buildInsertOneOperation = exports.ClientBulkWriteCommandBuilder = void 0;
exports.buildOperation = buildOperation;
const commands_1 = require("../../cmap/commands");
/** @internal */
class ClientBulkWriteCommandBuilder {
    /**
     * Create the command builder.
     * @param models - The client write models.
     */
    constructor(models, options) {
        this.models = models;
        this.options = options;
    }
    /**
     * Gets the errorsOnly value for the command, which is the inverse of the
     * user provided verboseResults option. Defaults to true.
     */
    get errorsOnly() {
        if ('verboseResults' in this.options) {
            return !this.options.verboseResults;
        }
        return true;
    }
    /**
     * Build the bulk write commands from the models.
     */
    buildCommands() {
        // Iterate the models to build the ops and nsInfo fields.
        const operations = [];
        let currentNamespaceIndex = 0;
        const namespaces = new Map();
        for (const model of this.models) {
            const ns = model.namespace;
            const index = namespaces.get(ns);
            if (index != null) {
                operations.push(buildOperation(model, index));
            }
            else {
                namespaces.set(ns, currentNamespaceIndex);
                operations.push(buildOperation(model, currentNamespaceIndex));
                currentNamespaceIndex++;
            }
        }
        const nsInfo = Array.from(namespaces.keys(), ns => ({ ns }));
        // The base command.
        const command = {
            bulkWrite: 1,
            errorsOnly: this.errorsOnly,
            ordered: this.options.ordered ?? true,
            ops: new commands_1.DocumentSequence(operations),
            nsInfo: new commands_1.DocumentSequence(nsInfo)
        };
        // Add bypassDocumentValidation if it was present in the options.
        if (this.options.bypassDocumentValidation != null) {
            command.bypassDocumentValidation = this.options.bypassDocumentValidation;
        }
        // Add let if it was present in the options.
        if (this.options.let) {
            command.let = this.options.let;
        }
        return [command];
    }
}
exports.ClientBulkWriteCommandBuilder = ClientBulkWriteCommandBuilder;
/**
 * Build the insert one operation.
 * @param model - The insert one model.
 * @param index - The namespace index.
 * @returns the operation.
 */
const buildInsertOneOperation = (model, index) => {
    const document = {
        insert: index,
        document: model.document
    };
    return document;
};
exports.buildInsertOneOperation = buildInsertOneOperation;
/**
 * Build the delete one operation.
 * @param model - The insert many model.
 * @param index - The namespace index.
 * @returns the operation.
 */
const buildDeleteOneOperation = (model, index) => {
    return createDeleteOperation(model, index, false);
};
exports.buildDeleteOneOperation = buildDeleteOneOperation;
/**
 * Build the delete many operation.
 * @param model - The delete many model.
 * @param index - The namespace index.
 * @returns the operation.
 */
const buildDeleteManyOperation = (model, index) => {
    return createDeleteOperation(model, index, true);
};
exports.buildDeleteManyOperation = buildDeleteManyOperation;
/**
 * Creates a delete operation based on the parameters.
 */
function createDeleteOperation(model, index, multi) {
    const document = {
        delete: index,
        multi: multi,
        filter: model.filter
    };
    if (model.hint) {
        document.hint = model.hint;
    }
    if (model.collation) {
        document.collation = model.collation;
    }
    return document;
}
/**
 * Build the update one operation.
 * @param model - The update one model.
 * @param index - The namespace index.
 * @returns the operation.
 */
const buildUpdateOneOperation = (model, index) => {
    return createUpdateOperation(model, index, false);
};
exports.buildUpdateOneOperation = buildUpdateOneOperation;
/**
 * Build the update many operation.
 * @param model - The update many model.
 * @param index - The namespace index.
 * @returns the operation.
 */
const buildUpdateManyOperation = (model, index) => {
    return createUpdateOperation(model, index, true);
};
exports.buildUpdateManyOperation = buildUpdateManyOperation;
/**
 * Creates a delete operation based on the parameters.
 */
function createUpdateOperation(model, index, multi) {
    const document = {
        update: index,
        multi: multi,
        filter: model.filter,
        updateMods: model.update
    };
    if (model.hint) {
        document.hint = model.hint;
    }
    if (model.upsert) {
        document.upsert = model.upsert;
    }
    if (model.arrayFilters) {
        document.arrayFilters = model.arrayFilters;
    }
    return document;
}
/**
 * Build the replace one operation.
 * @param model - The replace one model.
 * @param index - The namespace index.
 * @returns the operation.
 */
const buildReplaceOneOperation = (model, index) => {
    const document = {
        update: index,
        multi: false,
        filter: model.filter,
        updateMods: model.replacement
    };
    if (model.hint) {
        document.hint = model.hint;
    }
    if (model.upsert) {
        document.upsert = model.upsert;
    }
    return document;
};
exports.buildReplaceOneOperation = buildReplaceOneOperation;
/** @internal */
function buildOperation(model, index) {
    switch (model.name) {
        case 'insertOne':
            return (0, exports.buildInsertOneOperation)(model, index);
        case 'deleteOne':
            return (0, exports.buildDeleteOneOperation)(model, index);
        case 'deleteMany':
            return (0, exports.buildDeleteManyOperation)(model, index);
        case 'updateOne':
            return (0, exports.buildUpdateOneOperation)(model, index);
        case 'updateMany':
            return (0, exports.buildUpdateManyOperation)(model, index);
        case 'replaceOne':
            return (0, exports.buildReplaceOneOperation)(model, index);
    }
}
//# sourceMappingURL=command_builder.js.map