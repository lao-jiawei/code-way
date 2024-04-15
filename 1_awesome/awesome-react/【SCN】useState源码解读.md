1. react方法主入口==>react/packages/react/index.js

   ````javascript
   export {
     ...
     useState,
     ...
   } from './src/ReactClient';
   ````

2. 前往/src/ReactClient

   ````javascript
   import {
     ...,
     useState,
     ...
   } from './ReactHooks';
   ````

3. 前往/ReactHooks

   ```typescript
   export function useState<S>(
     initialState: (() => S) | S,
   ): [S, Dispatch<BasicStateAction<S>>] {
     const dispatcher = resolveDispatcher();
     return dispatcher.useState(initialState);
   }
   ```

   * resolveDispatcher