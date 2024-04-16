package commands

import "github.com/spf13/cobra"

func NewEncryptDataCmd() *Encrypt {
	_cmd := &Encrypt{}

	_cmd.Command = &cobra.Command{
		Use:   "encrypt",
		Short: "encrypt payload with assigned subject",
		RunE: func(cmd *cobra.Command, args []string) error {
			return _cmd.Execute(cmd)
		},
	}

	_cmd.Command.Flags().StringVarP(&_cmd.payload, "payload", "", "", "plain data to encrypt")
	_cmd.Command.MarkFlagRequired("payload")
	_cmd.Command.Flags().StringVarP(&_cmd.subject, "subject", "", "", "subject did")
	_cmd.Command.MarkFlagRequired("subject")

	return _cmd
}

type Encrypt struct {
	Command *cobra.Command
	payload string
	subject string
}

func (i *Encrypt) Execute(cmd *cobra.Command) error {
	// iotex_jwe_json_serialize("This is a JWE Test", Ecdh1puA256kw, A256cbcHs512, peerSignDID, peerSignJWK, recipients_kid, true);
	// TODO if encrypt payload with master key?
	return nil
}