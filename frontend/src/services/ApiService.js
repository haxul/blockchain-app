import { Api, JsonRpc } from "eosjs"
import JsonSignatureProvider from "eosjs/dist/eosjs-jssig"
import { resolve } from "dns"
import { reject } from "q"

const takeAction = async (action, dataValue) => {
  const privateKey = localStorage.getItem("cardgame_key")
  const rpc = new JsonRpc("https://eos-studio.api.dfuse.dev")
  const signatureProvider = new signatureProvider([privateKey])
  const api = new Api({
    rpc,
    signatureProvider,
    textDecoder: new TextDecoder(),
    textEncoder: new TextEncoder(),
  })

  try {
    const resultWithConfig = await api.transact(
      {
        actions: [
          {
            account: "haxul",
            name: action,
            authorization: [
              {
                actor: localStorage.getItem("cardgame_acount"),
                permission: "active",
              },
            ],
            data: dataValue,
          },
        ],
      },
      {
        blockBehind: 3,
        expireSeconds: 30,
      },
    )
  } catch (error) {
    console.error(error)
  }
}

export default class ApiService {
  static login({ username, key }) {
    return new Promise(
      ((respolve, reject) = () => {
        try {
          localStorage.setItem("cardgame_account", username)
          localStorage.setItem("cardgame_key", key)
          takeAction("login", { username }).then(() => resolve())
        } catch (err) {
          localStorage.removeItem("cardgame_active")
          localStorage.removeItem("cardgame_key")
          reject(err)
        }
      }),
    )
  }
}
